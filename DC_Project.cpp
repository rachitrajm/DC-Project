#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

string s = "    Quantization Process";
const double V_max = 40.0, V_min = -40.0, L = 16.0;

int main()
{
    cout << "\t\t\t";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
        Sleep (200);
    }

    int n;
    cout << "\n\n\nEnter the number of Samples: ";
    cin >> n;

    double samples[n], normalized_PAM[n], quantized[n], normalized_error[n];
    int quantization_code[n];

    const double d = (V_max-V_min) / L;																			//Calculating the value of d

    cout << "\nEnter the Samples:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> samples[i];
        normalized_PAM[i] = samples[i] / d;
    }

    for (int i = 0; i < n; i++)
    {
        if (normalized_PAM[i] >= -8.0 && normalized_PAM[i] < -7.0)      quantized[i]= -7.5;
        if (normalized_PAM[i] >= -7.0 && normalized_PAM[i] < -6.0)      quantized[i]= -6.5;
        if (normalized_PAM[i] >= -6.0 && normalized_PAM[i] < -5.0)      quantized[i]= -5.5;
        if (normalized_PAM[i] >= -5.0 && normalized_PAM[i] < -4.0)      quantized[i]= -4.5;
        if (normalized_PAM[i] >= -4.0 && normalized_PAM[i] < -3.0)      quantized[i]= -3.5;
        if (normalized_PAM[i] >= -3.0 && normalized_PAM[i] < -2.0)      quantized[i]= -2.5;
        if (normalized_PAM[i] >= -2.0 && normalized_PAM[i] < -1.0)      quantized[i]= -1.5;
        if (normalized_PAM[i] >= -1.0 && normalized_PAM[i] < 0.0)       quantized[i]= -0.5;
        if (normalized_PAM[i] >= 0.0 && normalized_PAM[i] < 1.0)        quantized[i]= 0.5;
        if (normalized_PAM[i] >= 1.0 && normalized_PAM[i] < 2.0)        quantized[i]= 1.5;
        if (normalized_PAM[i] >= 2.0 && normalized_PAM[i] < 3.0)        quantized[i]= 2.5;
        if (normalized_PAM[i] >= 3.0 && normalized_PAM[i] < 4.0)        quantized[i]= 3.5;
        if (normalized_PAM[i] >= 4.0 && normalized_PAM[i] < 5.0)        quantized[i]= 4.5;
        if (normalized_PAM[i] >= 5.0 && normalized_PAM[i] < 6.0)        quantized[i]= 5.5;
        if (normalized_PAM[i] >= 6.0 && normalized_PAM[i] < 7.0)        quantized[i]= 6.5;
        if (normalized_PAM[i] >= 7.0 && normalized_PAM[i] <= 8.0)       quantized[i]= 7.5;
    }

    double q_code[] = {-7.5, -6.5, -5.5, -4.5, -3.5, -2.5, -1.5, -0.5, 0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5};
    for (int i = 0; i < n; i++)
    {
        normalized_error[i] = quantized[i] - normalized_PAM[i];
        int j = 0;
        for (j = 0; j < 15; j++)
            if (quantized[i] == q_code[j])      break;
        quantization_code[i] = j;


    }

    cout << "\n\n\nSample      Normalized PAM      Quantized      Normalized      Quantization	  Encoded\n";			//Displaying the result
    cout << " Value          Value             Value           Error            Code             words\n\n";
    for (int i = 0; i < n; i++)
    {
        bitset <16> binary (quantization_code[i]);
        cout << samples[i] << "\t\t" << normalized_PAM[i] << "\t\t" << quantized[i] << "\t\t" << normalized_error[i] << "\t\t" << quantization_code[i] <<"\t\t"<<binary<<endl;
    }
    return 0;
}
