#include <iostream>
#include <algorithm>

struct Process {
    int id, burstTime;
};

void calculateFCFS(Process p[], int n, int turnaround[], int waiting[]) {
    waiting[0] = 0;
    for (int i = 1; i < n; i++) waiting[i] = waiting[i - 1] + p[i - 1].burstTime;
    for (int i = 0; i < n; i++) turnaround[i] = waiting[i] + p[i].burstTime;
}

void calculateSJF(Process p[], int n, int turnaround[], int waiting[]) {
    std::sort(p, p + n, [](const Process& a, const Process& b) { return a.burstTime < b.burstTime; });
    waiting[0] = 0;
    for (int i = 1; i < n; i++) waiting[i] = waiting[i - 1] + p[i - 1].burstTime;
    for (int i = 0; i < n; i++) turnaround[i] = waiting[i] + p[i].burstTime;
}

void displayResults(Process p[], int n, int turnaround[], int waiting[]) {
    std::cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
        std::cout << p[i].id << "\t" << p[i].burstTime << "\t\t" << waiting[i] << "\t\t" << turnaround[i] << "\n";
}

int main() {
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;
    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        std::cout << "Enter burst time for Process " << i + 1 << ": ";
        std::cin >> p[i].burstTime;
    }
    int turnaround[n], waiting[n];
    calculateFCFS(p, n, turnaround, waiting);
    std::cout << "\nFCFS Scheduling:\n";
    displayResults(p, n, turnaround, waiting);
    calculateSJF(p, n, turnaround, waiting);
    std::cout << "\nSJF Scheduling:\n";
    displayResults(p, n, turnaround, waiting);
    return 0;
}
