#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

string stringsarr[20];
string way[20];
string answer[20];
void findway(int w, int x, int y);
bool drawway (int w, int x, int y);

int main(){
    for (int i = 0; i < 20; i++) {
        string help;
        getline (cin, help);
        stringsarr[i] = help;
        way[i] = help;
        answer[i] = help;
    }
    way[0][0] = 'A';
    findway (0, 0, 0);
    drawway (way[19][29] - 'A', 29, 19);
    cout<<endl<<endl;
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 30; x++) {
            cout<<answer[y][x];
        }
        cout<<endl;
    }
}

bool drawway (int w, int x, int y) {
    if ((x == 0) && (y == 0)) {
        if (answer[y][x] == ' ') answer[y][x] = '.';
        if (answer[y][x] == '@') answer[y][x] = '*';
        return true;
    }

    if (x%30 > 0) {
        if ((way[y][x - 1] - 'A' <= w) && (way[y][x - 1] != '#')){
            way[y][x] = '#';
            if (drawway(way[y][x - 1] - 'A', x - 1, y)) {
                if (answer[y][x] == ' ') answer[y][x] = '.';
                if (answer[y][x] == '@') answer[y][x] = '*';
                return true;
            }
        }
    }

    if (x%30 < 29) {
        if ((way[y][x + 1] - 'A' <= w) && (way[y][x + 1] != '#')){
            way[y][x] = '#';
            if (drawway(way[y][x + 1] - 'A', x + 1, y)) {
                if (answer[y][x] == ' ') answer[y][x] = '.';
                if (answer[y][x] == '@') answer[y][x] = '*';
                return true;
            }
        }
    }

    if (y%30 > 0) {
        if ((way[y - 1][x] - 'A' <= w) && (way[y - 1][x] != '#')){
            way[y][x] = '#';
            if (drawway(way[y - 1][x] - 'A', x, y - 1)) {
                if (answer[y][x] == ' ') answer[y][x] = '.';
                if (answer[y][x] == '@') answer[y][x] = '*';
                return true;
            }
        }
    }

    if (y%30 < 29) {
        if ((way[y + 1][x] - 'A' <= w) && (way[y + 1][x] != '#')){
            way[y][x] = '#';
            if (drawway(way[y + 1][x] - 'A', x, y + 1)) {
                if (answer[y][x] == ' ') answer[y][x] = '.';
                if (answer[y][x] == '@') answer[y][x] = '*';
                return true;
            }
        }
    }
    return false;
}

void findway(int w, int x, int y) {
    if (x > 29) return;
    if (y > 19) return;
    if (x < 0) return;
    if (y < 0) return;

    if (x%30 > 0) {
        if ((way[y][x - 1] == ' ') ||
           ((way[y][x - 1] - 'A' > w) && (way[y][x - 1] != '#')) || (way[y][x - 1] == '@')){
            if (stringsarr[y][x - 1] == '@') {
                way[y][x - 1] = w + 1 + 'A';
                findway(w + 1, x - 1, y);
            }
            else {
                way[y][x - 1] = w + 'A';
                findway(w, x - 1, y);
            }
        }
    }

    if (x%30 < 29) {
        if ((way[y][x + 1] == ' ') ||
           ((way[y][x + 1] - 'A' > w) && (way[y][x + 1] != '#')) || (way[y][x + 1] == '@')){
            if (stringsarr[y][x + 1] == '@') {
                way[y][x + 1] = w + 1 + 'A';
                findway(w + 1, x + 1, y);
            }
            else {
                way[y][x + 1] = w + 'A';
                findway(w, x + 1, y);
            }
        }
    }

    if (y%20 > 0) {
        if ((way[y - 1][x] == ' ') ||
           ((way[y - 1][x] - 'A' > w) && (way[y - 1][x] != '#')) || (way[y - 1][x] == '@')){
            if (stringsarr[y - 1][x] == '@') {
                way[y - 1][x] = w + 1 + 'A';
                findway(w + 1, x, y - 1);
            }
            else {
                way[y - 1][x] = w + 'A';
                findway(w, x, y - 1);
            }
        }
    }

    if (y%20 < 19) {
        if ((way[y + 1][x] == ' ') ||
           ((way[y + 1][x] - 'A' > w) && (way[y + 1][x] != '#')) || (way[y + 1][x] == '@')){
            if (stringsarr[y + 1][x] == '@') {
                way[y + 1][x] = w + 1 + 'A';
                findway(w + 1, x, y + 1);
            }
            else {
                way[y + 1][x] = w + 'A';
                findway(w, x, y + 1);
            }
        }
    }
}
/*
           ###
 ######## ###@##@#######@####
@########     ##     ##   ###
          ## ###@### ## # #
 ####@###@## ###@### ## # # ##
  ##       # @@




*/

/*
 #############################
@                            #
 ##########################@ #
                             #
 ########################### #
                @            #
############################ #
############################ #
############################ #
############################ #
############################ #
############################ #
############################ #
############################ #
############################ #
############################ #
############################ #
############################ #
############################ #
############################


*/
