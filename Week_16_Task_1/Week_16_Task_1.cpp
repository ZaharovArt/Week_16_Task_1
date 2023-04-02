
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

char* ReplaceWord(char* text, char* str1, char* str2);
void Chang_A(char* text);
int How_Letters(char* text);
int How_Number(char* text);


int main()
{
	system("chcp 1251>nul");
	setlocale(LC_ALL, "RUS");


	char text[] = { "Eat more of these. soft french rolls. yes have some tea 12 4\0" };
	cout << text;
	char* str1 = new char[20];
	char* str2 = new char[20];
	cout << endl;
	cout << "введите слово которое нужно заменить: ";
	cin >> str1;
	cout << endl;
	cout << "введите слово которым нужно заменить: ";
	cin >> str2;
	cout << endl;
	cout << "Измененный текс: ";
	cout << ReplaceWord(text, str1, str2);
	cout << endl;
	cout << "Замена в тексте первой буквы в предложении: ";
	Chang_A(text);
	cout << text;
	cout << endl;
	cout << endl;
	How_Letters(text);
	cout << endl;
	How_Number(text);


}

char* ReplaceWord(char* text, char* str1, char* str2) {

	char* find_word = strstr(text, str1);
	char* new_text = new char[strlen(text) - strlen(str1) + strlen(str2) + 1];
	int i = 0;
	for (; i < find_word - text; i++) {
		new_text[i] = text[i];
	}
	for (; i < find_word - text + strlen(str2); i++) {
		new_text[i] = str2[i - (find_word - text)];
	}
	for (int j = 0; i < strlen(text) - strlen(str1) + strlen(str2) + 1; i++, j++) {
		new_text[i] = text[(find_word - text + strlen(str1)) + j];
	}
	return new_text;
}

void Chang_A(char* text) {
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == '.' && text[i + 1] == ' ' && text[i + 2] > 96 && text[i + 2] < 123) {
			text[i + 2] = text[i + 2] - 32;
		}
	}
}

int  How_Letters(char* text) {

	int k = 0;
	char alfavit[53] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
	for (int i = 0; i < strlen(alfavit); i++) {
		for (int j = 0; j < strlen(text); j++) {
			if (alfavit[i] == text[j]) {
				k++;
			}
		}
		((i + 1) % 10) ? cout << alfavit[i] << " - " << k << "\t" : cout << alfavit[i] << " - " << k << "\t" << endl;
		k = 0;
	}
	return 0;
}
int How_Number(char* text) {
	int k = 0;
	char number[53] = { "1234567890" };
	for (int i = 0; i < strlen(number); i++) {
		for (int j = 0; j < strlen(text); j++) {
			if (number[i] == text[j]) {
				k++;
			}
		}
		cout << number[i] << " - " << k << "\t";
		k = 0;
	}
	return 0;
}