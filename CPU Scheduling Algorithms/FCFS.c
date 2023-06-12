#include <stdio.h>

int burst[20], n, waiting[20], turnaround[20], time = 0;
void input() {
  printf("Enter No. of Processes: ");
  scanf("%d", & n);
  for (int i = 0; i < n; i++) {
    printf("Enter Burst time for P%d: ", i + 1);
    scanf("%d", & burst[i]);
  }
}
void calculateWaiting() {
  for (int i = 0; i < n; i++) {
    waiting[i] = time;
    time += burst[i];
  }
}
void calculateTurnAround() {
  for (int i = 0; i < n; i++) {
    turnaround[i] = waiting[i] + burst[i];
  }
}
void printTable() {
  printf("\tProcess\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
  for (int i = 0; i < n; i++) {
    printf("\tP%d\t\t%d\t\t%d\t\t%d \n", i + 1, burst[i], waiting[i], turnaround[i]);
  }
}
int calcAverage(int a[20]) {
  int sum = 0, avg;
  for (int i = 0; i < n; i++) {
    sum = sum + a[i];
  }
  avg = sum / n;
  return avg;
}
void ganttChart() {
  for (int i = 0; i < 3; i++) {
    // printf("|");
    for (int j = 0; j < n; j++) {
      printf("+");
      for (int k = 0; k < burst[j] * 1.5; k++) {
        if (k == (burst[j] / 2) && i == 1) {
          printf("P%d", j + 1);
        } else if (i != 1) {
          printf("-");
        } else if (k != (burst[j] / 2) + 1 && i == 1) {
          printf(" ");
        }
      }
      // printf("|\n");
    }
    printf("+\n");
  }
}
void main() {
  input();
  calculateWaiting();
  calculateTurnAround();
  printTable();
  printf("\nAverage Waiting Time is: %d", calcAverage(waiting));
  printf("\nAverage Turn Around Time is: %d \n", calcAverage(turnaround));
  printf("\nGantt Chart: \n");
  ganttChart();
}
