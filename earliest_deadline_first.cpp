#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent a process in the scheduling queue
struct Process {
    int id;             // Process ID
    int arrival_time;   // Arrival time of the process
    int execution_time; // Execution time of the process
    int deadline;       // Absolute deadline of the process
};

// Function to compare processes based on their absolute deadlines
bool cmp(Process a, Process b) {
    return a.deadline < b.deadline;
}

// Function to implement the Earliest Deadline First scheduling algorithm
void edf(vector<Process>& processes) {
    int time = 0;
    int n = processes.size();
    
    // Process each task in order of earliest deadline first
    for (int i = 0; i < n; i++) {
        // Find the process with the earliest absolute deadline
        int idx = -1;
        for (int j = 0; j < n; j++) {
            if (processes[j].arrival_time <= time && processes[j].execution_time > 0) {
                if (idx == -1 || processes[j].deadline < processes[idx].deadline) {
                    idx = j;
                }
            }
        }
        
        // If no process is ready, wait until the next process arrives
        if (idx == -1) {
            time = processes[i].arrival_time;
            idx = i;
        }
        
        // Execute the selected process for one time unit
        processes[idx].execution_time--;
        time++;
        
        // Check if the process has missed its deadline
        if (time > processes[idx].deadline) {
            cout << "Process " << processes[idx].id << " missed its deadline!" << endl;
        }
        
        // Check if the process has finished executing
        if (processes[idx].execution_time == 0) {
            cout << "Process " << processes[idx].id << " has completed." << endl;
        }
    }
}

int main() {
    // Define a set of processes with arrival time, execution time, and absolute deadline
    vector<Process> processes = {
        {0, 3, 5, 8},
        {1, 1, 2, 4},
        {2, 2, 3, 7},
        {3, 2, 4, 10}
    };
    
    // Sort the processes based on their absolute deadlines
    sort(processes.begin(), processes.end(), cmp);
    
    // Run the EDF scheduling algorithm on the set of processes
    edf(processes);
    
    return 0;
}
