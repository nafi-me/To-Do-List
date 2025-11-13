import json
import os

FILE = "tasks.json"

def load_tasks():
    if os.path.exists(FILE):
        with open(FILE, "r") as f:
            return json.load(f)
    return []

def save_tasks(tasks):
    with open(FILE, "w") as f:
        json.dump(tasks, f, indent=2)

def list_tasks(tasks):
    if not tasks:
        print("\nNo tasks yet!")
        return
    print("\nYour To-Do List:")
    for i, t in enumerate(tasks, 1):
        status = "✔" if t["done"] else "✗"
        print(f"{i}. [{status}] {t['title']}")

def add_task(tasks):
    title = input("Enter new task: ")
    tasks.append({"title": title, "done": False})
    save_tasks(tasks)
    print("Task added!")

def mark_done(tasks):
    list_tasks(tasks)
    try:
        n = int(input("Task number to mark done: "))
        tasks[n-1]["done"] = True
        save_tasks(tasks)
        print("Marked as done!")
    except:
        print("Invalid number!")

def delete_task(tasks):
    list_tasks(tasks)
    try:
        n = int(input("Task number to delete: "))
        tasks.pop(n-1)
        save_tasks(tasks)
        print("Task deleted!")
    except:
        print("Invalid number!")

def main():
    tasks = load_tasks()
    while True:
        print("\n==== To-Do Menu ====")
        print("1. View Tasks")
        print("2. Add Task")
        print("3. Mark Task Done")
        print("4. Delete Task")
        print("5. Exit")
        choice = input("Choose: ")

        if choice == "1":
            list_tasks(tasks)
        elif choice == "2":
            add_task(tasks)
        elif choice == "3":
            mark_done(tasks)
        elif choice == "4":
            delete_task(tasks)
        elif choice == "5":
            print("Goodbye!")
            break
        else:
            print("Invalid option!")

if __name__ == "__main__":
    main()
