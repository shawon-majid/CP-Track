//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;



int main(){

    int number_of_processes, number_of_resources; // number of process, number of resources
    cin >> number_of_processes >> number_of_resources;

    vector < int > total_resources(number_of_resources);

    for(int i = 0; i < number_of_resources; i++){
        cin >> total_resources[i];
    }

    int allocation[number_of_processes][number_of_resources];

    // allocate resources to the processes

    // cout << "allocate resources to the processes: ";

    for(int i = 0; i < number_of_processes; i++){
        for(int j = 0; j < number_of_resources; j++){
            cin >> allocation[i][j];
        }
    }

    int max_need[number_of_processes][number_of_resources];

    for(int i = 0; i < number_of_processes; i++){
        for(int j = 0; j < number_of_resources; j++){
            cin >> max_need[i][j];
        }
    }

    vector < int > available_resource(number_of_resources);

    int remaining_need[number_of_processes][number_of_resources];

    for(int i = 0; i < number_of_processes; i++){
        for(int j = 0; j < number_of_resources; j++){
            remaining_need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }

    vector < int > allocated_resource(number_of_resources);

    for(int i = 0; i < number_of_processes; i++){
        for(int j = 0; j < number_of_resources; j++){
            allocated_resource[j] += allocation[i][j];
        }
    }

    for(int i = 0; i < number_of_resources; i++){
        available_resource[i] = total_resources[i] - allocated_resource[i];
    }

    cout << "available_resource: ";

    for(auto x: available_resource){
        cout << x << " ";
    }
    cout << "\n";


    bool safe_state_exists = 1;

    vector < int > safe_sequence;
    vector < int > done_process(number_of_processes, 0);

    int process_completed = 0;

    while(process_completed < number_of_processes){

        bool any_safe_process = 0;

        for(int i = 0; i < number_of_processes; i++){

            bool current_process_safe = 1;

            for(int j = 0; j < number_of_resources; j++){
                if(available_resource[j] < remaining_need[i][j] || done_process[i]){ // i'th process diye hobe na
                    current_process_safe = 0;
                    break;
                }
            }

            if(current_process_safe){
                safe_sequence.push_back(i);
                done_process[i] = 1;
                process_completed++;

                for(int j = 0; j < number_of_resources; j++){
                    available_resource[j] += allocation[i][j];
                }

                any_safe_process = 1;
                break;
            }
        }

        if(any_safe_process == 0){
            safe_state_exists = 0;
            break;
        }
    }



    // 

    for(auto x: safe_sequence){
        cout << x << " ";
    }
    cout << "\n";




    return 0;
}