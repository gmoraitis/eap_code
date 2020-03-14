#include <stdio.h>
#define n 2
#define r 3
#define t 4

int main()
{
    float sum_f = 0,    // Σύνολο βαθμών των φοιτητητών.
        sum_tm = 0,     // Σύνολο μετρητη για τον μέσο όρο των τμηματων.
        mesos_oros,     // Μέσος όρος φοιτητών.
        mesos_oros_tm,  // Μέσος όρος τμηματων.
        f_kop = 0,      // Ποσοστο φοιτητών που δεν απεκτησαν δικαιωμα εξετασεων σε καθε τμημα.
        s_f_kop = 0,    // Συνολικο πληθως απο ολα τα τμηματα που δεν απεκτησαν δικαιωμα εξετασεων.
        array[n][r][t]; // Πίνακας 3 διαστάσεων.
    int i, j, k;        // Ακέραιες μεταβλητες των επαναληψεων.

    //  i)Υποερωτημα.
    for (i = 0; i < n; i++) // Επανάληψη για τα 2 τμήματα.
    {
        for (j = 0; j < r; j++) // Επανάληψη για τους φοιτητές.
        {

            for (k = 0; k < t; k++) // Επανάληψη για τα μαθήματα.
            {

                do
                {
                    printf("Εισαγωγή βαθμού %dου τμηματος  %dος φοιτητής , %dης εργασίας \n", i + 1, j + 1, k + 1);
                    scanf("%f", &array[i][j][k]);

                } while ((array[i][j][k] < 0) || (array[i][j][k] > 10));
            }
        }
    }

    // ii)Υποερωτημα
    for (i = 0; i < n; i++) // Επανάληψη για τα 2 τμήματα.
    {

        for (j = 0; j < r; j++) // Επανάληψη για τους φοιτητές.
        {
            sum_f = 0;
            for (k = 0; k < t; k++) // Επανάληψη για τα μαθήματα.
            {
                sum_f += array[i][j][k];
            }
            mesos_oros = (float)sum_f / t;

            printf("Ο μέσος όρος του %d φοιτητή του %d τμηματος είναι: %.1f\n", j + 1, i + 1, mesos_oros);
        }
    }

    // iii)Υποερωτημα
    for (i = 0; i < n; i++) // Επανάληψη για τα 2 τμήματα.
    {
        sum_tm = 0;
        for (j = 0; j < r; j++) // Επανάληψη για τους φοιτητές.
        {

            for (k = 0; k < t; k++) // Επανάληψη για τα μαθήματα.
            {

                sum_tm += array[i][j][k];
            }

            mesos_oros_tm = (float)sum_tm / (r * t);
        }
        printf("Ο μέσος όρος του %d τμηματος είναι: %.1f\n", i + 1, mesos_oros_tm);
    }

    for (i = 0; i < n; i++) // Επανάληψη για τα 2 τμήματα.
    {
        f_kop = 0;
        for (j = 0; j < r; j++) // Επανάληψη για τους φοιτητές.
        {
            sum_f = 0;
            for (k = 0; k < t; k++) // Επανάληψη για τα μαθήματα.
            {

                sum_f += array[i][j][k];
            }
            if (sum_f < 20)
            {
                f_kop ++;
            }
        }

        printf("To ποσοστο των κομμένων φοιτήτων του %d τμήματος είναι: %.1f %s\n", i + 1, (float)(f_kop / j) * 100,"%");
    }

s_f_kop = 0;

    for (i = 0; i < n; i++) // Επανάληψη για τα 2 τμήματα.
    {
        
        for (j = 0; j < r; j++) // Επανάληψη για τους φοιτητές.
        {
            sum_f = 0;
            for (k = 0; k < t; k++) // Επανάληψη για τα μαθήματα.
            {

                sum_f += array[i][j][k];
            }
            if (sum_f < 20)
            {
                s_f_kop++;
            }
        }
    }

    printf("To ποσοστο των κομμένων φοιτήτων όλων των τμηματων είναι: %d %s\n",(int) (s_f_kop /( n * r) ) * 100,"%");
}