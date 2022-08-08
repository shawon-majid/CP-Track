#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
struct Minion {
    int id, pos_r, pos_c, health, timeout;
};


int main()
{
    int height;
    int width;
    cin >> height >> width; cin.ignore();

    vector < string > grid(height);

    for (int i = 0; i < height; i++) {
        string row;
        cin >> row; cin.ignore();
        grid[i] = row;
    }
    int my_flag_base_r;
    int my_flag_base_c;
    cin >> my_flag_base_r >> my_flag_base_c; cin.ignore();
    int opponent_flag_base_r;
    int opponent_flag_base_c;
    cin >> opponent_flag_base_r >> opponent_flag_base_c; cin.ignore();
    string fire_name;
    int fire_price;
    int fire_damage;
    cin >> fire_name >> fire_price >> fire_damage; cin.ignore();
    string freeze_name;
    int freeze_price;
    int freeze_damage;
    cin >> freeze_name >> freeze_price >> freeze_damage; cin.ignore();
    string mine_name;
    int mine_price;
    int mine_damage;
    cin >> mine_name >> mine_price >> mine_damage; cin.ignore();

    bool flag_obtained = 0;
    bool opponent_took_flag = 0;
    bool fire_used = 0;
    bool khali3_pos_reached = 0;
    bool khali4_pos_reached = 0;


    int khali_pos_r, khali_pos_c;
    for(int i = 0; i < height; i++){
        if(grid[i][width/2] == '.'){
            khali_pos_r = i;
            khali_pos_c = width/2;
            break;
        }
    }

    int khali3_pos_r, khali3_pos_c;
    for(int i = 0; i < height; i++){
        if(grid[i][width-3] == '.'){
            khali3_pos_r = i;
            khali3_pos_c = width-3;
            break;
        }
    }

    int khali4_pos_r, khali4_pos_c;
    for(int i = height-1; i > 0; i--){
        if(grid[i][width-3] == '.'){
            khali4_pos_r = i;
            khali4_pos_c = width-3;
            break;
        }
    }


    // game loop
    while (1) {
        int my_score;
        int opponent_score;
        cin >> my_score >> opponent_score; cin.ignore();
        int my_flag_pos_r;
        int my_flag_pos_c;
        int my_flag_carrier;
        cin >> my_flag_pos_r >> my_flag_pos_c >> my_flag_carrier; cin.ignore();
        int opponent_flag_pos_r;
        int opponent_flag_pos_c;
        int opponent_flag_carrier;
        cin >> opponent_flag_pos_r >> opponent_flag_pos_c >> opponent_flag_carrier; cin.ignore();
        int my_alive_minion_cnt;
        cin >> my_alive_minion_cnt; cin.ignore();

        Minion myMinions[my_alive_minion_cnt];

        for (int i = 0; i < my_alive_minion_cnt; i++) {
            int id;
            int pos_r;
            int pos_c;
            int health;
            int timeout;
            cin >> id >> pos_r >> pos_c >> health >> timeout; cin.ignore();
            
            myMinions[i].id = id;
            myMinions[i].pos_r = pos_r;
            myMinions[i].pos_c = pos_c;
            myMinions[i].health = health;
            myMinions[i].timeout = timeout;
            
            if(pos_r == opponent_flag_pos_r && pos_c == opponent_flag_pos_c){
                flag_obtained = 1;
            }
            if(pos_r == khali3_pos_r && pos_c == khali3_pos_c){
                khali3_pos_reached = 1;
            }

            if(pos_r == khali4_pos_r && pos_c == khali4_pos_c){
                khali4_pos_reached = 1;
            }


        }

        

        int visible_minion_cnt; // opponent minions

        Minion opMinioins[visible_minion_cnt];

        cin >> visible_minion_cnt; cin.ignore();
        for (int i = 0; i < visible_minion_cnt; i++) {
            int id;
            int pos_r;
            int pos_c;
            int health;
            int timeout;
            cin >> id >> pos_r >> pos_c >> health >> timeout; cin.ignore();

            opMinioins[i].id = id;
            opMinioins[i].pos_r = pos_r;
            opMinioins[i].pos_c = pos_c;
            opMinioins[i].health = health;
            opMinioins[i].timeout = timeout;

            if(pos_r == my_flag_pos_r && pos_c == my_flag_pos_c){
                opponent_took_flag = 1;
            }    

        }

        


        int visible_coin_cnt;
        cin >> visible_coin_cnt; cin.ignore();
        for (int i = 0; i < visible_coin_cnt; i++) {
            int pos_r;
            int pos_c;
            cin >> pos_r >> pos_c; cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        // cerr << flag_obtained << endl;

        // for(int i = 0; i < my_alive_minion_cnt; i++){
        //     cerr << myMinions[i].id << endl;
        // }

        if(flag_obtained){
            // go to my flag_base_r and my flag_base_c
            
            cout << "MOVE " << opponent_flag_carrier << " " << my_flag_base_r << " " << my_flag_base_c << " | ";
            
        }
        else{
            // go and obtain the flag
            // 0'th id is the flag carrier;
            
            cout << "MOVE " << 0 << " " << opponent_flag_pos_r << " " << opponent_flag_pos_c << " | ";
            
        }
        int kk = 0;
        if(!fire_used){
            if(!opponent_took_flag){
                // go to the our base;
                
                cout << "MOVE " << 1 << " " << my_flag_pos_r<< " " << my_flag_pos_c << " | ";
                
            }
            else{
                if(my_score > freeze_price){
                    
                    cout << "FREEZE " << 1 << " | ";
                    fire_used = 1;
                }
            }
        }
        else{
            cerr << kk << endl;
            kk++;
            if((kk == 0) && my_score > fire_price){
                cout << "FIRE " << 1 << " | ";
            }
            else cout << "MOVE " << 1 << " " << opponent_flag_pos_r << " " << opponent_flag_pos_c << " | ";
            
        }
        
        int x = 2;
        
        if(flag_obtained){
            if(opponent_flag_carrier == 2){
                x = 0;
            }
        }
        
        if(my_alive_minion_cnt-1 != 2) cout << "MOVE " << x << " " << opponent_flag_pos_r << " " << opponent_flag_pos_c << " | ";
        else {
            cout << "MOVE " << x << " " << opponent_flag_pos_r << " " << opponent_flag_pos_c << endl;
            continue;
        }

        if(my_alive_minion_cnt - 1 != 3 ){
            if(!khali3_pos_reached){
                cout << "MOVE " << 3 << " " << khali3_pos_r << " " << khali3_pos_c << " | ";
            }
            else{
                cout << "MOVE " << 3 << " " << my_flag_pos_r << " " << my_flag_pos_c << " | ";
            }
            
        }
        else{
            if(!khali3_pos_reached){
                cout << "MOVE " << 3 << " " << khali3_pos_r << " " << khali3_pos_c << endl;
            }
            else{
                cout << "MOVE " << 3 << " " << my_flag_pos_r << " " << my_flag_pos_c << endl;
            }
            
            continue;
        }

        if(my_alive_minion_cnt - 1 != 4 ){
            // cout << "MOVE " << 4 << " " << khali4_pos_r << " " << khali4_pos_c << " | ";
            if(!khali4_pos_reached){
                cout << "MOVE " << 4 << " " << khali4_pos_r << " " << khali4_pos_c << " | ";
            }
            else{
                cout << "MOVE " << 4 << " " << my_flag_pos_r << " " << my_flag_pos_c << " | ";
            }
        }
        else{

            //cout << "MOVE " << 4 << " " << khali4_pos_r << " " << khali4_pos_c << endl;
            if(!khali4_pos_reached){
                cout << "MOVE " << 4 << " " << khali4_pos_r << " " << khali4_pos_c << endl;
            }
            else{
                cout << "MOVE " << 4 << " " << my_flag_pos_r << " " << my_flag_pos_c << endl;
            }
            
            continue;
        }
        

    }
}