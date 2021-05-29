// Banker's Algorithm
#include <iostream>
using namespace std;

int main()
{

    int n, m;


    cout<<"Enter Processes and Resources Number: "<<endl;
    cin>>n>>m;

    int i, j, k;
    int available[m]= {0};
    int allocation[n][m]= {0};
    int maximum_allocation[n][m]= {0};


    cout<<"Enter Available Resources for first process: "<<endl;



        for(j=0; j<m; j++)
        {
            cin>>available[j];
        }



    cout<<"Enter Allocated Resource: "<<endl;
   for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>allocation[i][j];

        }
    }



    cout<<"Enter Maximum Capacity:"<<endl;

       for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>maximum_allocation[i][j];
        }
    }




    int finished[n]={0}, processes[n]={0}, process_serial_no = 0;
    for (i = 0; i < n; i++)
    {
        finished[i] = 0;
    }


    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
        need[i][j] = maximum_allocation[i][j] - allocation[i][j];

        }
    }
    int y = 0;

    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (finished[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    processes[process_serial_no++] = i;
                    for (y = 0; y < m; y++)
                        available[y] += allocation[i][y];
                    finished[i] = 1;
                }
            }
        }
    }

    cout << "Processes are execute through this sequence:" << endl;
    for (i = 0; i < n - 1; i++){
     cout << " P" << processes[i] << " ->";
    }

    cout << " P" << processes[n - 1] <<endl;

    return 0;
}


