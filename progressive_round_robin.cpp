#include <iostream>
#include <queue>

using namespace std;

// Define a structure to represent a process in the scheduling queue
struct Process {
    int id;             // Process ID
    int arrival_time;   // Arrival time of the process
    int execution_time; // Execution time of the process
    int remaining_time; // Remaining execution time of the process
    int quantum;        // Time quantum assigned to the process
};

// Function to implement the Progressive Round-Robin scheduling algorithm
void prr(queue<Process>& processes, int default_quantum) {
    int time = 0;
    int n = processes.size();
    int quantum_increase = default_quantum / 10; // 10% increase in time quantum
    
    // Process each task in a round-robin fashion
    while (!processes.empty()) {
        Process p = processes.front();
        processes.pop();
        
        // Execute the process for its assigned time quantum or until it finishes
        int remaining_time = p.remaining_time;
        int quantum = p.quantum;
        while (remaining_time > 0) {
            if (quantum > remaining_time) {
                quantum = remaining_time;
            }
            
            // Execute the process for one time quantum
            for (int i = 0; i < quantum; i++) {
                time++;
                remaining_time--;
                
                // Check if the process has finished executing
                if (remaining_time == 0) {
                    cout << "Process " << p.id << " has completed." << endl;
                    break;
                }
                
                // Check if the time quantum should be increased or decreased
                if (i == quantum - 1 && remaining_time > 0) {
                    if (quantum == p.quantum) {
                        quantum += quantum_increase;
                    } else {
                        quantum = p.quantum;
                    }
                }
            }
            
            // Check if the time quantum should be increased or decreased
            if (remaining_time > 0) {
                if (quantum == p.quantum) {
                    quantum += quantum_increase;
                } else {
                    quantum = p.quantum;
                }
            }
        }
    }
}

int main() {
    // Define a set of processes with arrival time and execution time
    queue<Process> processes;
    processes.push({0, 0, 5, 5, 2});
    processes.push({1, 1, 3, 3, 4});
    processes.push({2, 2, 7, 7, 3});
    processes.push({3, 3, 4, 4, 2});
    
    // Run the PRR scheduling algorithm on the set of processes
    prr(processes, 2); // Default time quantum is 2
    
    return 0;
}
