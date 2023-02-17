//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;

int HEIGHT, WIDTH;

struct window{



    int x, y;
    int h, w;
};

vector <window > windows;

bool valueInRange(int value, int min, int max)
{ return (value >= min) && (value <= max); }

bool checkOverlap(int x, int y, int w, int h){

    for(auto win: windows){

        bool xOverlap = valueInRange(win.x, x, x + w) || valueInRange(x, win.x, win.x + win.w);

        bool yOverlap = valueInRange(win.y, y, y + h) || valueInRange(y, win.y, win.y + win.h);

        if(xOverlap && yOverlap){
            return 1;
        }
    }

    if(x + w > WIDTH || y + h > HEIGHT) return 1;

    return 0;
}

bool checkOverlap2(int x, int y, int w, int h, vector<window>::iterator found){

    for(auto it = windows.begin(); it != windows.end(); it++){

        if(it == found){
            continue;
        }

        window win = *it;


        bool xOverlap = valueInRange(win.x, x, x + w) || valueInRange(x, win.x, win.x + win.w);

        bool yOverlap = valueInRange(win.y, y, y + h) || valueInRange(y, win.y, win.y + win.h);

        if(xOverlap && yOverlap){
            return 1;
        }
    }

    if(x + w > WIDTH || y + h > HEIGHT) return 1;

    return 0;
}



auto isThereWindow(int x, int y){

    for(auto it = windows.begin(); it != windows.end(); it++){

        window win = *it;

        if(x >= win.x && x <= win.x + win.w && y >= win.y && y <= win.y+win.h){
            return it;
        }
    }

    return windows.end();

}


int main(){


    

    cin >> WIDTH >> HEIGHT;

    string command;

    int cnt = 1;

    while(cin >> command){

        cout << "command "<< cnt <<": ";

        if(command == "OPEN"){
            int x, y, w, h;
            cin >> x >> y >> w >> h;

            // check current windows if it overlaps or not

            bool overlapped = checkOverlap(x, y, w, h);


            if(overlapped){
                cout << "window does not fit\n";
            }
            else{

                cout << "window added\n";

                window win;
                win.x = x;
                win.y = y;
                win.h = h;
                win.w = w;

                windows.push_back(win);
            }
        }

        if(command == "CLOSE"){
            int x, y;
            cin >> x >> y;

            auto found = isThereWindow(x, y);

            if(found == windows.end()){
                cout << "no window at given position\n";
            }
            else{
                cout << "window closed\n";
                windows.erase(found);
            }
        }

        if(command == "RESIZE"){
            int x, y, w, h;

            cin >> x >> y >> w >> h;

            auto found = isThereWindow(x, y);

            if(found == windows.end()){
                cout << "no window at given position\n";
            }
            else{
                window win = *found;
                x = win.x;
                y = win.y;

                bool overlapped = checkOverlap2(x, y, w, h, found);



                if(overlapped){
                    cout << "window does not fit\n";
                }
                else{

                    cout << "resized\n";
                    windows.erase(found);
                    win.h = h;
                    win.w = w;
                    windows.push_back(win);
                }
            }
        }

        if(command == "MOVE"){
            int x, y, dx, dy;
            cin >> x >> y >> dx >> dy;   

            auto found = isThereWindow(x, y);

            if(found == windows.end()){
                cout << "no window at given position\n";
            }
            else{
                if(dx){
                    // 
                    queue < window > resets;

                    resets.push(*found);

                    while(resets.empty()){

                        window current = resets.top();
                        resets.pop();


                        


                    }


                }
            }


        }



        cnt++;

    }


    return 0;
}