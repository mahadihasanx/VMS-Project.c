#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h> //Clearing Terminal
#include <windows.h> //Delay Affect & SetConsoleOutputCP

//Global Functions
#define Max_Vehicles 100
int vehicles[Max_Vehicles][5]; // (ID, type, hour, min, am/pm)
int vehicle_count = 0; // Number of Vehicle Registered

void Welcome_Message();
void Starting_System();
void menu();
void head_Message(int *choice_pointer);
void continue_exit(int *continue_terminate);

//Menu Settings//
void Register_Vehicles();
void Display_All_Vehicles();
void is_Valid_Time(int *entry_hour, int *entry_min);
void Remove_Vehicle();
void Search_Vehicle();
void Update_Time();

int main()
{
    SetConsoleOutputCP(CP_UTF8); //Required for Special Symbols
    system("cls"); //Clears Console Screen

    Welcome_Message(); //Intro Message
    printf("\n");
    
    for(int i = 0; i<=15; i++)
        printf(" ");
    printf("Press any key to start the system...\n\n");
    getch(); //Clears Terminal
    
    Starting_System(); //Delay
    system("cls"); //Clears Console Screen
    
    menu(); //Main Menu
    return 0;
}

void Welcome_Message()
{
    //Title
    printf("╔");
    for(int i = 0; i<=68; i++) //Border Line
    {
        printf("═");
    }
    printf("╗");

    printf("\n║"); //Border Line with Spaces
    for(int i = 0; i<69; i++)
    {
        printf(" ");
    }
    printf("║\n");

    printf("║");
    for(int i = 0; i<=16; i++)
    {
        printf(" ");
    }
    printf("🚗 VEHICLE MANAGEMENT SYSTEM (VMS)");
    for(int i = 0; i<=17; i++)
    {
        printf(" ");
    }
    printf("║\n");

    printf("║");
    for(int i = 0; i<69; i++)
    {
        printf(" ");
    }
    printf("║\n");

    printf("╚");
    for(int i = 0; i<=68; i++)
    {
        printf("═");
    }
    printf("╝\n");

    //////////////////////////
    printf("╔");
    for(int i = 0; i<=68; i++)
        printf("═");
    printf("╗\n");
    printf("║"); //Border Line with Spaces
    for(int i = 0; i<69; i++)
    {
        printf(" ");
    }
    printf("║\n");


    printf("║");
    for(int i = 0; i<=9; i++)
    {
        printf(" ");
    }
    printf("Welcome to the Vehicle Management System project!");
    for(int i = 0; i<=9; i++)
    {
        printf(" ");
    }
    printf("║\n");
    printf("║");
    for(int i = 0; i<69; i++)
    {
        printf(" ");
    }
    printf("║\n");

    //Statement 1 and 2
    printf("║");
    for(int i = 0; i<=12; i++)
    {
        printf(" ");
    }
    printf("→ Developed by: Department of CSE");
    for(int i = 0; i<=22; i++)
    {
        printf(" ");
    }
    printf("║\n");

    printf("║");
    for(int i = 0; i<=12; i++)
    {
        printf(" ");
    }
    printf("→ Semester: Spring 2025");
    for(int i = 0; i<=32; i++)
    {
        printf(" ");
    }
    printf("║\n");

    printf("║"); //Border Line with Spaces
    for(int i = 0; i<69; i++)
    {
        printf(" ");
    }
    printf("║\n");

    //This system allows you to

    printf("║");
    for(int i = 0; i<=12; i++)
    {
        printf(" ");
    }
    printf("This system allows you to:");
    for(int i = 0; i<=29; i++)
    {
        printf(" ");
    }
    printf("║\n");

    //Menu 1
    printf("║");
    for(int i = 0; i<=13; i++)
    {
        printf(" ");
    }
    printf("• Register new vehicles");
    for(int i = 0; i<=31; i++)
    {
        printf(" ");
    }
    printf("║\n");

    //Menu 2
    printf("║");
    for(int i = 0; i<=13; i++)
    {
        printf(" ");
    }
    printf("• Remove Vehicles");
    for(int i = 0; i<=37; i++)
    {
        printf(" ");
    }
    printf("║\n");

    //Menu 3
    printf("║");
    for(int i = 0; i<=13; i++)
    {
        printf(" ");
    }
    printf("• Display all records");
    for(int i = 0; i<=33; i++)
    {
        printf(" ");
    }
    printf("║\n");

    //Menu 4
    printf("║");
    for(int i = 0; i<=13; i++)
    {
        printf(" ");
    }
    printf("• Search and update entry times");
    for(int i = 0; i<=23; i++)
    {
        printf(" ");
    }
    printf("║\n");

    printf("║"); //Border Line with Spaces
    for(int i = 0; i<69; i++)
    {
        printf(" ");
    }
    printf("║\n");

    printf("╚");
    for(int i = 0; i<=68; i++) //Border Line
    {
        printf("═");
    }
    printf("╝\n");
}

void Starting_System()
{
    for(int i = 0; i<=20; i++)
        printf(" ");

    //Delay affect
    printf("Starting the system");
    for (int i = 0; i < 3; i++) 
    {
        Sleep(500); // Half-second delay
        printf(".");
    }
}

void menu()
{
    printf("╔");
    for(int i = 0; i<=38; i++)
        printf("═");
    printf("╗\n");

    printf("║");
    for(int i = 0; i<=12; i++)
        printf(" ");
    printf("VHS MAIN MENU");
    for(int i = 0; i<=12; i++)
        printf(" ");
    printf("║\n");   
    printf("╚");
    for(int i = 0; i<=38; i++)
        printf("═");
    printf("╝\n");

    printf("╔");
    for(int i = 0; i<=38; i++)
        printf("═");
    printf("╗\n");

    printf("║");
    for(int i = 0; i<=38; i++)
        printf(" ");
    printf("║\n");

    printf("║");
    for(int i = 0; i<=5; i++)
        printf(" ");
    printf("[1] Register New Vehicle");
    for(int i = 0; i<=8; i++)
        printf(" ");
    printf("║\n");

    printf("║");
    for(int i = 0; i<=5; i++)
        printf(" ");
    printf("[2] Remove Vehicle");
    for(int i = 0; i<=14; i++)
        printf(" ");
    printf("║\n");

    printf("║");
    for(int i = 0; i<=5; i++)
        printf(" ");
    printf("[3] Display All Vehicles");
    for(int i = 0; i<=8; i++)
        printf(" ");
    printf("║\n");

    printf("║");
    for(int i = 0; i<=5; i++)
        printf(" ");
    printf("[4] Search By Vehicle ID");
    for(int i = 0; i<=8; i++)
        printf(" ");
    printf("║\n");

    printf("║");
    for(int i = 0; i<=5; i++)
        printf(" ");
    printf("[5] Update Vehicle Entry Time");
    for(int i = 0; i<=3; i++)
        printf(" ");
    printf("║\n");

    printf("║");
    for(int i = 0; i<=5; i++)
        printf(" ");
    printf("[6] Exit");
    for(int i = 0; i<=24; i++)
        printf(" ");
    printf("║\n");

    printf("║");
    for(int i = 0; i<=38; i++)
        printf(" ");
    printf("║\n");

    printf("╚");
    for(int i = 0; i<=38; i++)
        printf("═");
    printf("╝\n");

    //Choice
    int choice;
    do
    {
        printf("Enter Choice: ");
        scanf("%d", &choice);
        if(choice<1 || choice>6)
            printf("Invalid Input!\n\n");
    }while(choice<1 || choice>6);

    system("cls"); //Clears Console Screen
    head_Message(&choice); //Display Head Message
}

void head_Message(int *choice_pointer)
{
    int n;
    if (*choice_pointer == 1)
    {
        for (int i = 0; i < 43; i++)
            printf("=");
        printf("\n|        🔧  Register New Vehicle         |\n");
        for (int i = 0; i < 43; i++)
            printf("=");
        printf("\n");
        Register_Vehicles();
        printf("\nBack To Menu [1]\tExit [2]\n\nYour Choice: ");
        scanf("%d", &n);
        continue_exit(&n);
        
    }

    else if (*choice_pointer == 2)
    {
        for (int i = 0; i < 43; i++)
            printf("=");
        printf("\n|         ❌  Remove Vehicle              |\n");
        for (int i = 0; i < 43; i++)
            printf("=");
        printf("\n");
        Remove_Vehicle();
        printf("\nBack To Menu [1]\tExit [2]\n\nYour Choice: ");
        scanf("%d", &n);
        continue_exit(&n);
    }

    else if (*choice_pointer == 3)
    {
        for (int i = 0; i < 46; i++)
            printf("=");
        printf("\n|          👁️   Display All Vehicles          |\n");
        for (int i = 0; i < 46; i++)
            printf("=");
        printf("\n");
        Display_All_Vehicles();
        printf("\nBack To Menu [1]\tExit [2]\n\nYour Choice: ");
        scanf("%d", &n);
        continue_exit(&n);
    }

    else if (*choice_pointer == 4)
    {
        for (int i = 0; i < 43; i++)
            printf("=");
        printf("\n|      🔍  Search by Vehicle ID           |\n");
        for (int i = 0; i < 43; i++)
            printf("=");
        printf("\n");
        Search_Vehicle();
        printf("\nBack To Menu [1]\tExit [2]\n\nYour Choice: ");
        scanf("%d", &n);
        continue_exit(&n);
    }

    else if (*choice_pointer == 5)
    {
        for (int i = 0; i < 43; i++)
            printf("=");
        printf("\n|     ⏰  Update Vehicle Entry Time       |\n");
        for (int i = 0; i < 43; i++)
            printf("=");
        printf("\n");
        Update_Time();
        printf("\nBack To Menu [1]\tExit [2]\n\nYour Choice: ");
        scanf("%d", &n);
        continue_exit(&n);
    }

    else if (*choice_pointer == 6)
    {
    for (int i = 0; i < 43; i++)
        printf("=");
    printf("\n|   🙏  Thank You For Using Our System!   |\n");
    for (int i = 0; i < 43; i++)
        printf("=");
    printf("\n");
    exit(0); // Terminates the program
    }
}

void Register_Vehicles()
{
    int id, car_type, am_pm;
    int entry_hour, entry_min; //Declaring them to call them inside function

    if(vehicle_count>Max_Vehicles)
    {
        printf("⚠️ Cannot Register More!");
        return;
    }

    for(int i = 0; i<2; i++)
        printf(" ");
    printf("• Enter Vehicle ID: ");
    scanf("%d", &id);
    
    for(int i = 0; i<4; i++)
        printf(" ");
    printf("[1] Bike  [2] Car  [3] Truck\n");
    do
    {
        for(int i = 0; i<2; i++)
        printf(" ");
        printf("• Enter Type: ");
        scanf("%d", &car_type);
        if(car_type>3 || car_type<1)
        {
            for(int i = 0; i<2; i++)
                printf(" ");
            printf("🚫 Inavlid Input!\n");
        }           
    }while(car_type>3 || car_type<1);

    is_Valid_Time(&entry_hour, &entry_min);

    do
    {
        for(int i = 0; i<2; i++)
        printf(" ");
        printf("• Enter AM [1] or PM [2]: ");
        scanf("%d", &am_pm);
        if(am_pm<1 || am_pm>2)
        {
            for(int i = 0; i<2; i++)
                printf(" ");
            printf("🚫 Inavlid Input!\n");
        }
    } while (am_pm<1 || am_pm>2);

    //Inputing inside Array
    vehicles[vehicle_count][0] = id;
    vehicles[vehicle_count][1] = car_type;
    vehicles[vehicle_count][2] = entry_hour;
    vehicles[vehicle_count][3] = entry_min;
    vehicles[vehicle_count][4] = am_pm;

    vehicle_count ++;
    
    printf("\n✅ Vehicle Registered Successfully!\n");
}

void is_Valid_Time(int *entry_hour, int *entry_min)
{
    do
    {
        for(int i = 0; i<2; i++)
        printf(" ");
        printf("• Enter Entry Hour (1-12): ");
        scanf("%d", entry_hour);
        if(*entry_hour<1 || *entry_hour>12)
        {
            for(int i = 0; i<2; i++)
                printf(" ");
            printf("🚫 Inavlid Input!\n");
        }
    }while(*entry_hour<1 || *entry_hour>12);

    do
    {
        for(int i = 0; i<2; i++)
        printf(" ");
        printf("• Enter Entry Minute (1-59): ");
        scanf("%d", entry_min);
        if(*entry_min<1 || *entry_min>59)
        {
            for(int i = 0; i<2; i++)
                printf(" ");
            printf("🚫 Inavlid Input!\n");
        }
    } while (*entry_min<1 || *entry_min>59);
}

void Display_All_Vehicles()
{
    int cars[vehicle_count][6];
    for(int i = 0; i<1; i++)
    {
        printf("\t");
        for(int j = 0; j<4; j++)
        {
            if(j==0)
            {
                printf("No.\t");
            }
            else if(j==1)
            {
                printf("ID\t");
            }
            else if(j==2)
            {
                printf("Type\t");
            }
            else if(j==3)
            {
                printf("Time\t");
            }
        }
        printf("\n\n");
    }
    
    for(int i = 0; i<vehicle_count; i++)
    {
        printf("\t");
        for(int j = 0; j<6; j++)
        {
            if(j==0)
            {
                cars[i][j] = i+1;
                printf("%d\t", cars[i][j]);
            }
            else if(j == 1)
            {
                cars[i][j] = vehicles[i][j-1];
                printf("%d\t", cars[i][j]);
            }
            else if(j == 2)
            {
                cars[i][j] = vehicles[i][j-1];
                if(cars[i][j] == 1)
                    printf("Car\t");
                else if(cars[i][j] == 2)
                    printf("Bike\t");
                else if(cars[i][j] == 3)
                    printf("Truck\t");
            }
            else if(j == 3)
            {
                cars[i][j] = vehicles[i][j-1];
                printf("%d:", cars[i][j]);
            }
            else if(j == 4)
            {
                cars[i][j] = vehicles[i][j-1];
                printf("%d ", cars[i][j]);
            }
            else if(j == 5)
            {
                cars[i][j] = vehicles[i][j-1];
                if(cars[i][j] == 1)
                    printf("AM");
                else if(cars[i][j] == 2)
                    printf("PM");
            }
        }

        printf("\n");
    }
}

void continue_exit(int *continue_terminate)
{
    if (*continue_terminate == 1)
    {
        system("cls");
        menu();
    }
    else if(*continue_terminate == 2)
    {
        system("cls");
        for (int i = 0; i < 43; i++)
        printf("=");
        printf("\n|   🙏  Thank You For Using Our System!   |\n");
        for (int i = 0; i < 43; i++)
        printf("=");
        printf("\n");
        exit(0); // Terminates the program
    }
}

void Remove_Vehicle()
{
    int target_vehicle, match = -1;
    printf("Enter Vehicle ID: ");
    scanf("%d", &target_vehicle);

    for(int i = 0; i<vehicle_count; i++)
        {
            if(vehicles[i][0] == target_vehicle)
            {
                match = i;
                break;
            }
        }
    
    if (match != -1)
    {
        for(int i = match; i<vehicle_count-1; i++)
        {
            for(int j = 0; j<5; j++)
            {
                vehicles[i][j] = vehicles[i+1][j];
            }
        }

        for(int j = 0; j<5; j++)
        {
            vehicles[vehicle_count-1][j] = 0;
        }

        vehicle_count--;
        printf("\n✅ Vehicle Removed Successfully!\n");
    }

    else
        printf("\n❌ Vehicle Not Found!\n");
}

void Search_Vehicle()
{
    int search, found = 0;
    printf("   Enter Vehicle ID: ");
    scanf("%d", &search);

    for(int i = 0; i<vehicle_count; i++)
    {
        if(vehicles[i][0] == search)
        {
            printf("\n   ✅ Vehicle Found\n\n");
            printf("   ID: %d\n", vehicles[i][0]);
            if(vehicles[i][1] == 1)
                printf("   Type: Bike\n");
            else if(vehicles[i][1] == 2)
                printf("   Type: Car\n");
            else if(vehicles[i][1] == 3)
                printf("   Type: Truck\n");
            printf("   Time: ");
            printf("%d:", vehicles[i][2]);
            printf("%d ", vehicles[i][3]);
            if(vehicles[i][4] == 1)
                printf("AM\n");
            else if(vehicles[i][4] == 2)
                printf("PM\n");
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\n\t❌ Vehicle Not Found!\n");
    }
}

void Update_Time()
{
    int target_vehicle, found = 0, new_hour, new_min, new_am_pm;
    printf("Enter Vehicle ID: ");
    scanf("%d", &target_vehicle);

    for(int i = 0; i<vehicle_count; i++)
    {
        if(vehicles[i][0] == target_vehicle)
        {
            printf("\n✅ Vehicle Found!\n\n");
            printf("Enter Updated Entry Hour: ");
            scanf("%d", &new_hour);
            vehicles[i][2] = new_hour;
            printf("Enter Updated Entry Minute: ");
            scanf("%d", &new_min);
            vehicles[i][3] = new_min;
            printf("   AM [1] PM [2]\n");
            printf("Enter Updated Time Period: ");
            scanf("%d", &new_am_pm);
            vehicles[i][4] = new_am_pm;

            printf("\n✅ Vehicle Entry Time Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\n❌ Vehicle Not Found!\n");
}