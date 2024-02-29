#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Function to mark attendance for an active worker
void markAttendance(vector<string>& workers, vector<vector<bool>>& attendance, const vector<bool>& isActive, const string& workerName, int day) {
    auto it = find(workers.begin(), workers.end(), workerName);

    if (it != workers.end()) {
        // Worker found
        size_t index = distance(workers.begin(), it);

        if (isActive[index]) {
            // Worker is active, mark attendance for the specified day
            attendance[index][day] = true;
            cout << "Attendance marked for " << workerName << " on Day " << day + 1 << endl;
        } else {
            // Worker is not active
            cout << "Inactive worker: " << workerName << ". Attendance not marked for Day " << day + 1 << endl;
        }
    } else {
        // Worker not found
        cout << "Worker not found: " << workerName << ". Attendance not marked for Day " << day + 1 << endl;
    }
}

// Function to display attendance status for each day
void displayAttendance(const vector<string>& workers, const vector<vector<bool>>& attendance) {
    cout << "Attendance Status:\n";
    cout << setw(20) << left << "Worker Name";

    for (int day = 0; day < 5; ++day) {
        cout << setw(15) << left << "Day " << day + 1;
    }

    cout << endl;

    for (size_t i = 0; i < workers.size(); ++i) {
        cout << setw(20) << left << workers[i];

        for (int day = 0; day < 5; ++day) {
            cout << setw(15) << left << (attendance[i][day] ? "Present" : "Absent");
        }

        cout << endl;
    }
}

int main() {
    vector<string> workers;
    vector<vector<bool>> attendance; // 2D vector for attendance (workers x days)
    vector<bool> isActive;

    int numWorkers;
    cout << "Enter the number of workers: ";
    cin >> numWorkers;

    // Input worker names and set active status to true for all workers initially
    for (int i = 0; i < numWorkers; ++i) {
        string workerName;
        bool activeStatus;

        cout << "Enter name for worker " << i + 1 << ": ";
        cin >> workerName;
        cout << "Is worker " << workerName << " active? (1 for yes, 0 for no): ";
        cin >> activeStatus;

        workers.push_back(workerName);
        isActive.push_back(activeStatus);
        attendance.push_back(vector<bool>(5, false)); // Initialize attendance to false (absent) for each day initially
    }

    // Mark attendance for each day
    for (int day = 0; day < 5; ++day) {
        cout << "\nDay " << day + 1 << ":\n";
        int numAttendees;
        cout << "Enter the number of workers present today: ";
        cin >> numAttendees;

        for (int i = 0; i < numAttendees; ++i) {
            string workerName;
            cout << "Enter name of worker present " << i + 1 << ": ";
            cin >> workerName;
            markAttendance(workers, attendance, isActive, workerName, day);
        }
    }

    // Display attendance for each day
    displayAttendance(workers, attendance);

    return 0;
}
