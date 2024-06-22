#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <fstream>
using namespace std;

const string currentDateTime()
{
    char buf[80];
    time_t now = time(0);
    struct tm tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

void report(string rusername, string ractivity, string rtarget, string rdetail, string rtime) {
    fstream fr("Report.txt", ios::app);
    fr << rusername << ' ' << ractivity << ' ' << rtarget << ' ' << rdetail << ' ' << rtime << endl;
    fr.close();
}