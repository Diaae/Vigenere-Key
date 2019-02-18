/*

Vigenère Key

Name: Diaae Bakri

*/

#include <iostream>
#include <string>
using namespace std;

string OriginalText;
string mappedkey;

void  TextAndKey(){
/*
This method contains:

· Convert input text to lowercase
· Convert key to uppercase
· Match the length of the encryption key with the length of the text using keymap string variable
· If the text contains a space add space to the key as well
· // if the messsage length still less than the key length 
· Extend the key if the key ends before the text
*/
	string text, key;
	cout << "Please input some text: " << endl;
	getline(cin, text);
	for (int i = 0; i < text.length(); i++){
		text[i] = tolower(text[i]);
	}
	cout << "Please input a key: " ;
	getline(cin, key);
	for (int i = 0; i < key.length(); i++){
		key[i] = toupper(key[i]);
	}
	string keymap = "";
	for (int i = 0, j = 0; i < text.length(); i++){
		if (text[i] == 32){ 
			keymap += 32;
		}
		else{
			if (j<key.length()){
				keymap += key[j];
				j++;
		}
		else{
				j = 0; // 
				keymap += key[j];
				j++;
			}
		}
	}
	cout << " The text is: " << text <<endl  ;
	cout << " The key is: " << keymap << endl ;
	OriginalText = text ;
	mappedkey = keymap ;
}
/*
*/
int tablearr[26][26];
void  createVigenereSquare()
{
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
		{
			int temp;
			if ((i + 65) + j > 90)
			// if we reached 'Z' just go back to 'A'
			{
				temp = (i + 65) + j - 26;
				tablearr[i][j] = temp;
			}
			else
			{
				temp = (i + 65) + j;
				//just fill with letters after 'A'
				tablearr[i][j] = temp;
			}
		}
}
void  Encryption(string OriginalText,string mappedkey)
{
	 createVigenereSquare();
	string encryptedtext = " ";
	
		int index = 0;

		for (int i = 0; i < OriginalText.length(); i++)
		{
			if (OriginalText[i] == ' ') continue;

			if (mappedkey[index] == ' ')
			//if the letter of the key is space we compute new index until we reach letter 
			{
				for (int j = 0; j < mappedkey.length(); j++)
				{

					index = (index + 1) % mappedkey.length();
					if (mappedkey[index] != ' ')
						break;
				}
			}
			int x = (int)OriginalText[i] - 97;
			//we compute the first index of the letter of the encrypted Text by substracting 97 from the asci code of the specific letter from the Text because it is in lower case
			int y = (int)mappedkey[i] - 65;
			//we compute the second index of the letter of the encrypted Text by substracting 65 from the asci code of the specific letter from the key because it is in upper case
			encryptedtext += (char)tablearr[x][y];

		

	}
	cout << "Encrypted Text is: " + encryptedtext << endl;
}
int getCount (int key,int text)
{
	int count = 0;
	string result = "";
	for (int i = 0; i < 26; i++){
		if (key + i > 90)
		{
			result += (char)(key + (i - 26)+32);
		}
		else{
			result += (char)(key + i+32);
		}
	}
	for (int i=0;i<result.length();i++){
		if (result[i] == text)
		{
			break;
		}
		else{
			count++ ;
		}
	}
	return count;
}

void  Decryption(string OriginalText, string mappedkey){
	string decryptedmessage = " ";
	int index = 0;
	for (int i = 0; i < OriginalText.length(); i++)
	{
		if (OriginalText[i] == 32 && mappedkey[i] == 32)
		{
			decryptedmessage += " ";
		}else {
			int temp = getCount((int)mappedkey[i], (int)OriginalText[i]);
			decryptedmessage += (char)(temp + 97);
		}
	}
	cout << "Decrypted Text is " + decryptedmessage << endl;
}

/*
	Main function
*/
int main()
{
	int choice;
	cout << "Please enter an alphabetic text To encrypt please press 1 for decryption press 2" << endl;
	cin >> choice;
	cin.ignore();
	if (choice == 1){
		cout << "Encryption :" << endl;
		TextAndKey();
		Encryption(OriginalText, mappedkey);
	}
	else if (choice==2){
		cout << "Decryption :" << endl;
		TextAndKey();
		Decryption(OriginalText, mappedkey);
	}
	else{
		cout << "Please choose a value 1 or 2" << endl;
	}
	return 0;
}