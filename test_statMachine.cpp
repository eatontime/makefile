#include <iostream>
using namespace std;

typedef enum{
    OPENED,
    CLOSED,
    LOCKED,
}  State;

typedef enum{
    OPEN,
    CLOSE,
    LOCK,
    UNLOCK
} Event;

typedef struct{
    State currentState;
    Event event;
    State NextState;
} StateTransfer;

typedef struct{
    State state;
    int transferTimes;
}Door;

StateTransfer g_stateTransferTable[]{
    {OPENED, CLOSE,  CLOSED},
    {CLOSED, OPEN,   OPENED},
    {CLOSED, LOCK,   LOCKED},
    {LOCKED, UNLOCK, CLOSED},
        };

void toOpen(Door& door);
void toClose(Door& door);
void toLock(Door& door);
typedef void (*pfToState)(Door& door);
pfToState g_pFun[] = {toOpen, toClose, toLock}; //状态枚举值对应下标

void toOpen(Door& door){
    door.state = OPENED;
    cout << "open the door!\n";
}

void toClose(Door& door){
    door.state = CLOSED;
    cout << "close the door!\n";
}

void toLock(Door& door){
    door.state = LOCKED;
    cout << "lock the door!\n";
}

void transfer(Door& door,const Event event){
    for (int i = 0; i < sizeof(g_stateTransferTable)/sizeof(StateTransfer); ++i) {
        if(door.state == g_stateTransferTable[i].currentState &&
           event == g_stateTransferTable[i].event){
            g_pFun[g_stateTransferTable[i].NextState](door);
            door.transferTimes++;
            cout << "transfer ok!\n";
            return;
        }
    }
    cout << "This event cannot transfer current state!!\n";
    return;
}

void printDoor(const Door& door){
    string stateNote[] = {"opened","closed","locked"}; // 下标正好对应状态枚举值
    cout << "the door's state is: " << stateNote[door.state] << endl;
    cout << "the door transfer times is: " << door.transferTimes << endl;
}

int main(){
    Door door = {CLOSED, 0};
    printDoor(door);
    transfer(door, OPEN);
    printDoor(door);
    transfer(door, LOCK);
    printDoor(door);
    transfer(door, CLOSE);
    printDoor(door);
    return 0;
}