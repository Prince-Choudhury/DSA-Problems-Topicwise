// 2.Implement Lamport's logical Clock
#include <iostream>
#include <vector>

using namespace std;

class LamportClock {
private:
    vector<int> clocks;

public:
    // Constructor: Initializes LamportClock with the given number of processes.
    LamportClock(int numProcesses) {
        clocks.resize(numProcesses, 0);
    }

    // Increment the Lamport Clock for the specified process.
    void increment(int processId) {
        clocks[processId]++;
    }

    // Update the Lamport Clock with external clocks received from other processes.
    // This method ensures that the local clock values are updated to reflect the latest events.
    void update(const vector<int>& externalClocks) {
        for (int i = 0; i < clocks.size(); i++) {
            clocks[i] = max(clocks[i], externalClocks[i]);
        }
    }

    // Get the current Lamport Clock values for all processes.
    const vector<int>& getClocks() const {
        return clocks;
    }
};

int main() {
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    LamportClock clock(numProcesses);

    int processId;
    cout << "Enter the process ID (0-" << numProcesses - 1 << "): ";
    cin >> processId;

    int numEvents;
    cout << "Enter the number of events for process " << processId << ": ";
    cin >> numEvents;

    for (int i = 0; i < numEvents; i++) {
        clock.increment(processId);

        // Print the current Lamport Clocks for all processes after each event.
        cout << "Event " << i + 1 << " - Process " << processId << " Lamport Clocks: ";
        const vector<int>& clocks = clock.getClocks();
        for (int j = 0; j < clocks.size(); j++) {
            cout << clocks[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
