#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string title;
    bool done;
};

vector<Task> loadTasks() {
    vector<Task> tasks;
    ifstream file("tasks.txt");
    string line;
    while (getline(file, line)) {
        bool done = line.rfind("[x]", 0) == 0;
        string title = line.substr(3);
        tasks.push_back({title, done});
    }
    file.close();
    return tasks;
}

void saveTasks(const vector<Task>& tasks) {
    ofstream file("tasks.txt");
    for (auto &t : tasks) {
        file << (t.done ? "[x]" : "[ ]") << t.title << "\n";
    }
    file.close();
}

void listTasks(const vector<Task>& tasks) {
    cout << "\nYour To-Do List:\n";
    if (tasks.empty()) {
        cout << "No tasks yet!\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << (tasks[i].done ? "[✔]" : "[ ]") 
             << " " << tasks[i].title << "\n";
    }
}

int main() {
    vector<Task> tasks = loadTasks();
    int choice;

    do {
        cout << "\n==== To-Do List ====\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Mark Task Done\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            listTasks(tasks);
        } 
        else if (choice == 2) {
            cout << "Enter task: ";
            string title;
            getline(cin, title);
            tasks.push_back({title, false});
            saveTasks(tasks);
            cout << "Added!\n";
        } 
        else if (choice == 3) {
            listTasks(tasks);
            cout << "Enter task number: ";
            int num;
            cin >> num;
            if (num > 0 && num <= tasks.size()) {
                tasks[num - 1].done = true;
                saveTasks(tasks);
                cout << "Marked as done!\n";
            } else {
                cout << "Invalid number.\n";
            }
        }
    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}
