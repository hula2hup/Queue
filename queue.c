#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmptyQueue(Queue *q) {
    return q->front == -1;
}

int isFullQueue(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (!isFullQueue(q)) {
        if (isEmptyQueue(q)) {
            q->front = 0;
        }
        q->data[++(q->rear)] = value;
    }
}

int dequeue(Queue *q) {
    if (!isEmptyQueue(q)) {
        int value = q->data[q->front];
        if (q->front == q->rear) {
            initQueue(q);
        } else {
            q->front++;
        }
        return value;
    }
    return -1;
}

void printQueue(Queue *q) {
    if (!isEmptyQueue(q)) {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    } else {
        printf("Antrian kosong\n");
    }
}

int main() {
    int choice, counter = 1;
    Queue q;
    initQueue(&q);
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&q, counter++);
                printQueue(&q);
                break;
            case 2:
                if (!isEmptyQueue(&q)) {
                    printf("Nomor antrian %d diproses\n", dequeue(&q));
                } else {
                    printf("Tidak ada antrian\n");
                }
                printQueue(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}
