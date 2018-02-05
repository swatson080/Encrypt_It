/****************************************
* *11/11/2017* *
*****************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void textIn(const int size, char * pText);

void processText(const int size, int * pLen, char * pText);

void buildKey(const int asize, bool * pCrypt, char * pEncrypt, const char * pRead, char * pKey);

void printAlph(const int asize, const char * pRead);

void printKey(const int asize, char * pKey);

void printText(char * pText, int len);

void encryptIt(const int asize, int len, char * pText, const char * pRead, char * pKey);


int main()
{
int len;
int * pLen = &len;

const int SIZE = 256;
const int ASIZE = 26;

char text[SIZE] = {};
char * pText = text;

const char read[ASIZE] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const char * pRead = read;

char key[ASIZE];
char * pKey = key;

char encrypt[ASIZE] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
char * pEncrypt = encrypt;

bool crypt[ASIZE] = {};
bool * pCrypt = crypt;


textIn(SIZE,pText);
processText(SIZE, pLen, pText);
printText(pText, len);
buildKey(ASIZE, pCrypt, pEncrypt, pRead, pKey);
printAlph(ASIZE, pRead);
printKey(ASIZE, pKey);
encryptIt(ASIZE, len, pText, pRead, pKey);
printText(pText, len);

return 0;
}

/***************************************
Function Implementations
***************************************/

void printAlph(const int asize, const char * pRead) {
cout << "ALB: " << flush;
for (int i = 0; i < asize; i++) {
cout << pRead[i] << ' ' << flush;
}
cout << endl;
}

void printKey(const int asize, char * pKey) {
cout << "KEY: " << flush;
for (int i = 0; i < asize; i++) {
cout << pKey[i] << ' ' << flush;
}
cout << endl;
}

void printText(char * pText, int len) {
cout << "OUT: " << flush;
for (int i = 0; i < len; i++) {
cout << pText[i] << flush;
}
cout << endl;
}

void textIn(const int size, char * pText) {
cout << "Enter up to " << size - 1 << " characters to be encrypted\n> " << flush;
cin.getline(pText, size);
}

void processText(const int size, int * pLen, char * pText) {
for (int i = 0; i < size; i++) {
if (pText[i] == 0) {
*pLen = i;
break;
}
if (isupper(pText[i])) {
pText[i] = tolower(pText[i]);
}
}
}

void buildKey(const int asize, bool * pCrypt, char * pEncrypt, const char * pRead, char * pKey) {
for (int i = 0; i < asize; i++) {
int setChar;
srand(time(NULL));
do {
setChar = rand() % 26;
// Prevent the same character being included in key more than once
if (pCrypt[setChar]) {
continue;
}
// Prevent encrypt from setting chars that are equal to read e.g. 'a'='a' - not sure if this works yet
else if (pEncrypt[setChar] == pRead[i]) {
continue;
}
else {
pKey[i] = pEncrypt[setChar];
pCrypt[setChar] = true;
break;
}
} while (true);
}
}

void encryptIt(const int asize, int len, char * pText, const char * pRead, char * pKey) {
for (int i = 0; i < len; i++) {
if (pText[i] == ' ' || pText[i] == '\n' || ispunct(pText[i]) || isdigit(pText[i])) {
continue;
}
for (int j = 0; j<asize; j++) {
if (pRead[j] == pText[i]) {
pText[i] = pKey[j];
break;
}
}
}
}
