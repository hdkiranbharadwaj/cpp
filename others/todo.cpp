#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool isCompleted;
};

// Function to display the menu
void showMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

// Function to add a task
void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter task description: ";
    std::cin.ignore(); // Ignore newline character left in the input buffer
    std::getline(std::cin, description);
    tasks.push_back({description, false});
    std::cout << "Task added successfully!" << std::endl;
}

// Function to view tasks
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to show!" << std::endl;
        return;
    }

    std::cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description
                  << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        std::cout << "Task marked as completed!" << std::endl;
    } else {
        std::cout << "Invalid task number!" << std::endl;
    }
}

// Function to remove a task
void removeTask(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed successfully!" << std::endl;
    } else {
        std::cout << "Invalid task number!" << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting the To-Do List Manager. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid option! Please try again." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
