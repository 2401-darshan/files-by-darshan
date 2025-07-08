#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    char username[15];
    char name[15];
    int age;
    char gender[10];
    char disease[20];
    char password[20];
};

struct Doctor {
    char name[30];
    char specialization[30];
    char schedule[50];
};

struct Appointment {
    char patientUsername[30];
    char doctorName[30];
    char date[20];
};

struct Room {
    int roomNo;
    int isAllocated;
    char patientUsername[30];
};

struct Billing {
    char patientUsername[30];
    float amount;
};

void main() {
    FILE *fp;
    int choice, loginSuccess = 0;
    char username[15], password[20];
    struct Patient p, newp;
    struct Doctor d;
    struct Appointment a;
    struct Room r;
    struct Billing b;

    while (1) {
        printf("\n=== Hospital Management System ===\n");
        printf("1. Admin Login\n2. Patient Login\n3. Register Patient\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Admin Username: ");
                scanf("%s", username);
                printf("Enter Password: ");
                scanf("%s", password);
                if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
                    printf("Admin Login successful.\n");
                    while (1) {
                        printf("\n--- Admin Dashboard ---\n");
                        printf("1. Add Patient\n2. View Patients\n3. Delete Patient\n4. Add Doctor\n5. View Doctors\n");
                        printf("6. Schedule Appointment\n7. View Appointments\n8. Allocate Room\n9. View Rooms\n");
                        printf("10. Billing\n11. Logout\n");
                        int adminChoice;
                        scanf("%d", &adminChoice);
                        getchar();

                        if (adminChoice == 1) {
                            printf("Enter Username: ");
							scanf("%s", p.username);
                            printf("Enter Name: ");
							scanf("%s", p.name);
                            printf("Enter Age: ");
							scanf("%d", &p.age);
                            printf("Enter Gender: ");
							scanf("%s", p.gender);
                            printf("Enter Disease: ");
							scanf("%s", p.disease);
                            printf("Enter Password: ");
							scanf("%s", p.password);
                            fp = fopen("patients.dat", "ab");
                            fwrite(&p, sizeof(p), 1, fp);
                            fclose(fp);
                            printf("Patient added.\n");
                        } else if (adminChoice == 2) {
                            fp = fopen("patients.dat", "rb");
                            while (fread(&p, sizeof(p), 1, fp)) {
                                printf("%s %s %d %s %s\n", p.username, p.name, p.age, p.gender, p.disease);
                            }
                            fclose(fp);
                        } else if (adminChoice == 3) {
                            char delUser[30];
                            printf("Enter patient username to delete: ");
                            scanf("%s", delUser);
                            FILE *temp = fopen("temp.dat", "wb");
                            fp = fopen("patients.dat", "rb");
                            while (fread(&p, sizeof(p), 1, fp)) {
                                if (strcmp(p.username, delUser) != 0) {
                                    fwrite(&p, sizeof(p), 1, temp);
                                }
                            }
                            fclose(fp);
                            fclose(temp);
                            remove("patients.dat");
                            rename("temp.dat", "patients.dat");
                            printf("Patient deleted.\n");
                        } else if (adminChoice == 4) {
                            printf("Enter Doctor Name: ");
							scanf("%s", d.name);
                            printf("Specialization: ");
							scanf("%s", d.specialization);
                            printf("Schedule: ");
							scanf("%s", d.schedule);
                            fp = fopen("doctors.dat", "ab");
                            fwrite(&d, sizeof(d), 1, fp);
                            fclose(fp);
                        } else if (adminChoice == 5) {
                            fp = fopen("doctors.dat", "rb");
                            while (fread(&d, sizeof(d), 1, fp)) {
                                printf("%s %s %s\n", d.name, d.specialization, d.schedule);
                            }
                            fclose(fp);
                        } else if (adminChoice == 6) {
                            printf("Patient Username: ");
							scanf("%s", a.patientUsername);
                            printf("Doctor Name: ");
							scanf("%s", a.doctorName);
                            printf("Date: ");
							scanf("%s", a.date);
                            fp = fopen("appointments.dat", "ab");
                            fwrite(&a, sizeof(a), 1, fp);
                            fclose(fp);
                        } else if (adminChoice == 7) {
                            fp = fopen("appointments.dat", "rb");
                            while (fread(&a, sizeof(a), 1, fp)) {
                                printf("%s with Dr.%s on %s\n", a.patientUsername, a.doctorName, a.date);
                            }
                            fclose(fp);
                        } else if (adminChoice == 8) {
                            printf("Room No: ");
							scanf("%d", &r.roomNo);
                            printf("Patient Username: ");
							scanf("%s", r.patientUsername);
                            r.isAllocated = 1;
                            fp = fopen("rooms.dat", "ab");
                            fwrite(&r, sizeof(r), 1, fp);
                            fclose(fp);
                        } else if (adminChoice == 9) {
                            fp = fopen("rooms.dat", "rb");
                            while (fread(&r, sizeof(r), 1, fp)) {
                                printf("Room %d - %s\n", r.roomNo, r.isAllocated ? r.patientUsername : "Available");
                            }
                            fclose(fp);
                        } else if (adminChoice == 10) {
                            printf("Enter patient username: ");
							scanf("%s", b.patientUsername);
                            printf("Enter amount: ");
							scanf("%f", &b.amount);
                            fp = fopen("billing.dat", "ab");
                            fwrite(&b, sizeof(b), 1, fp);
                            fclose(fp);
                        } else if (adminChoice == 11) {
                            break;
                        }
                    }
                } else {
                    printf("Invalid admin credentials.\n");
                }
                break;

            case 2:
                printf("Enter Username: ");
                scanf("%s", username);
                printf("Enter Password: ");
                scanf("%s", password);
                loginSuccess = 0;
                fp = fopen("patients.dat", "rb");
                while (fread(&p, sizeof(p), 1, fp)) {
                    if (strcmp(p.username, username) == 0 && strcmp(p.password, password) == 0) {
                        loginSuccess = 1;
                        break;
                    }
                }
                fclose(fp);
                if (loginSuccess) {
                    printf("Patient Login successful.\n");
                    while (1) {
                        printf("\n--- Patient Dashboard ---\n");
                        printf("1. View My Details\n2. Book Appointment\n3. View Appointments\n4. Room Status\n5. Billing Info\n6. Logout\n");
                        int patientChoice;
                        scanf("%d", &patientChoice);
                        if (patientChoice == 1) {
                            fp = fopen("patients.dat", "rb");
                            while (fread(&p, sizeof(p), 1, fp)) {
                                if (strcmp(p.username, username) == 0) {
                                    printf("%s %s %d %s %s\n", p.username, p.name, p.age, p.gender, p.disease);
                                }
                            }
                            fclose(fp);
                        } else if (patientChoice == 2) {
                            strcpy(a.patientUsername, username);
                            printf("Enter Doctor Name: ");
							scanf("%s", a.doctorName);
                            printf("Enter Date: ");
							scanf("%s", a.date);
                            fp = fopen("appointments.dat", "ab");
                            fwrite(&a, sizeof(a), 1, fp);
                            fclose(fp);
                        } else if (patientChoice == 3) {
                            fp = fopen("appointments.dat", "rb");
                            while (fread(&a, sizeof(a), 1, fp)) {
                                if (strcmp(a.patientUsername, username) == 0) {
                                    printf("With Dr.%s on %s\n", a.doctorName, a.date);
                                }
                            }
                            fclose(fp);
                        } else if (patientChoice == 4) {
                            fp = fopen("rooms.dat", "rb");
                            while (fread(&r, sizeof(r), 1, fp)) {
                                if (strcmp(r.patientUsername, username) == 0) {
                                    printf("You are allocated to Room %d\n", r.roomNo);
                                }
                            }
                            fclose(fp);
                        } else if (patientChoice == 5) {
                            fp = fopen("billing.dat", "rb");
                            while (fread(&b, sizeof(b), 1, fp)) {
                                if (strcmp(b.patientUsername, username) == 0) {
                                    printf("Your bill is: %.2f\n", b.amount);
                                }
                            }
                            fclose(fp);
                        } else if (patientChoice == 6) {
                            break;
                        }
                    }
                } else {
                    printf("Invalid patient credentials.\n");
                }
                break;

            case 3:
                printf("Choose a username: ");
				scanf("%s", newp.username);
                printf("Name: ");
				scanf("%s", newp.name);
                printf("Age: ");
				scanf("%d", &newp.age);
                printf("Gender: ");
				scanf("%s", newp.gender);
                printf("Disease: ");
				scanf("%s", newp.disease);
                printf("Choose a password: ");
				scanf("%s", newp.password);
                fp = fopen("patients.dat", "ab");
                fwrite(&newp, sizeof(newp), 1, fp);
                fclose(fp);
                printf("Registered successfully.\n");
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
