#include<iostream>
#include<fstream>		//File stream (ôàéëîâûå ïîòîêè)
using namespace std;

//#define WRITE_TOFILE
//#define READ_FROM_FILE
//#define work201

int StringLength(char str[]);
void Proverka(char str[]);
void Zamena(char str[]);

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//cout << "Hello World" << endl;
	ofstream fout("file.txt", ios::app); //Ñîçäàåì è îòêðûâàåì ïîòîê
	fout << "Hello World" << endl;
	fout.close(); //Ïîòîêè îáÿçàòåëüíî íóæíî çàêðûâàòü
	system("more file.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	ifstream fin; //ñîçäàåì ïîòîê
	fin.open("file.txt");
	const unsigned int SIZE = 1024;
	char sz_buffer[SIZE]{};//â ýòó ñòðîêó áóäåì ÷èòàòü èç ôàéëà sz_ - String Zero(ñòðîêà çàêàí÷èâàþùàÿñÿ íóëåì) 
	if (fin.is_open()) // ïðîâåðÿåì, îòêðûò ëè ôàéë
	{
		//TODO:åñëè îòêðûò áóäåì ÷èòàòü ôàéë
		while (!fin.eof())
		{
			//eof() - end of file
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}
	fin.close();
#endif // READ_FROM_FILE

	//Â ôàéëå 201 RAW.txt ïîìåíÿòü ìåñòàìè ñòîëáèêè ñ ÌÀÑ-àäðåñîì, è IP-àäðåñîì
	//Èñõîäíûé ôàéë äîëæåí îñòàòüñÿ íåèçìåííûì, ïðîãðàììà äîëæíà ñîçäàòü íîâûé èçìåíåííûé ôàéë
	//201 ready.txt

#ifdef work201
	ifstream fin;
	fin.open("201 RAW.txt");
	ofstream fout("201 ready.txt");
	const unsigned int IP_SIZE = 16;
	const unsigned int MAC_SIZE = 18;
	char sz_ip_buffer[IP_SIZE]{};
	char sz_mac_buffer[MAC_SIZE]{};
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			//cout << sz_ip_buffer << '\t';
			//cout << sz_mac_buffer << '\n';
			fout << sz_mac_buffer << '\t';
			fout << sz_ip_buffer << '\n';
		}
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}
	fout.close();
	fin.close();
#endif // work201
	ifstream fin;
	char OpenFileName[100] = {};
	char NewFileName[100] = {};
	cout << "Ââåäèòå èìÿ îòêðûâàåìîãî ôàéëà:"; cin.getline(OpenFileName, 100);
	cout << "Ââåäèòå èìÿ ñîõðàíÿåìîãî ôàéëà:"; cin.getline(NewFileName, 100);
	Proverka(OpenFileName);
	Proverka(NewFileName);
	fin.open(OpenFileName);
	ofstream fout(NewFileName);

	const unsigned int IP_SIZE = 16;
	const unsigned int MAC_SIZE = 18;
	char sz_ip_buffer[IP_SIZE]{};
	char sz_mac_buffer[MAC_SIZE]{};

	int i = 1;

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			Zamena(sz_mac_buffer);
			if (i != 5)
			{
				fout << "host 201-" << i << '\n';
				fout << "{" << '\n';
				fout << '\t' << "hardware ethernet" << '\t' << sz_mac_buffer << ";" << '\n';
				fout << '\t' << "fixed-address" << '\t' << '\t' << sz_ip_buffer << ";" << '\n';
				fout << "}" << '\n';
				fout << '\n';
			}
			else
			{
				fout << "host 201-" << i << '\n';
				fout << "#{" << '\n';
				fout << "#" << '\t' << "hardware ethernet" << '\t' << sz_mac_buffer << ";" << '\n';
				fout << "#" << '\t' << "fixed-address" << '\t' << '\t' << sz_ip_buffer << ";" << '\n';
				fout << "#}" << '\n';
				fout << '\n';
			}
			i++;
		}
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}

	fout.close();
	fin.close();
	system("notepad");
}

int StringLength(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void Proverka(char str[])
{
	int n = StringLength(str);
	if (str[n - 4] != '.' || str[n - 3] != 't' || str[n - 2] != 'x' || str[n - 1] != 't')
	{
		str[n] = '.';
		str[n + 1] = 't';
		str[n + 2] = 'x';
		str[n + 3] = 't';
	}
}

void Zamena(char str[])
{
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '-')str[i] = ':';
	}
}


/*
	Ðàáîòà ñ ôàéëàìè
	Ðàáîòà ñ ôàéëïìè â ÿçûêå ñ++ î÷åíü ïîõîæà íà âûâîä íà ýêðàí è ââîä ñ êëàâèàòóðû
	äëÿ âûâîäà íà ýêðàí ìû èñïîëüçóåì ïîòîê cout à äëÿ ââîäà ñ êëàâèàòóðû ïîòîê cin
	àíàëîãè÷íî äëÿ âûâîäà èíôîðìàöèè â ôàéë èñïîëüçóåòñÿ ïîòîê fout äëÿ ÷òåíèÿ ôàéëà èñïîëüçóåòñÿ ïîòîê fin
	cout ÿâëÿåòñÿ îáúýêòîì êëàññà (ostream - ïîòîê âûâîäà) à cin êëàññà (istream - ïîòîê ââîäà)
	fout ÿâëÿåòñÿ îáúýêòîì êëàññà (ofstream - output file stream(ïîòîê âûâîäà â ôàéë)) à fin êëàññà (ifstream - Input file stream(ïîòîê ââîäà â ôàéë))
	Åäèíñòâåííûì ðàçëè÷èåì ïîòîêîâ ââîäà âûâîäà ñ êëàâèàòóðû è íà ýêðàí(cin cout) è ïîòîêàìè ââîäà âûâîäà èç ôàéëà â ôàéë ÿâëÿåòñÿ òî ÷òî cin/cout óæå ñóùåñòâóþò à fin/fout íóæíî ñîçäàâàòü íåïîñðåäñòâåííî ïåðåä ÷òåíèåì/çàïèñüþ ôàéëà.
	Ïîòîêè cin/cout íàõîäÿòñÿ â áèáëèîòåêè iostream
	Ïîòîêè fin/fout íàõîäÿòñÿ â áèáëèîòåêè fstream
*/