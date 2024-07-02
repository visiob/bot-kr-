#include <iostream>
#include <tchar.h>
#include <string>
#include <Windows.h>

using namespace std;

struct personal {
	string user_name;
	string bot_name;
	string style_com;
	string gender;
};

personal enter() {
	personal temp;

	cout << "������ �� ��� �������� ���: ";
	getline(cin, temp.user_name);
	cout << "������ �� �� ������ �������� ����: ";
	getline(cin, temp.bot_name);
	while (true) {
		cout << "������ ����� ���������� � ����(���������/������): ";
		getline(cin, temp.style_com);
		if (temp.style_com == "���������" || temp.style_com == "������") {
			break;
		}
		else {
			cout << "������ ��� ���! ��� ������������ ������� ��������� ���, �� � ������� �������." << endl;
		}
	}
	while (true) {
		cout << "������ ���� �����(�/�): ";
		getline(cin, temp.gender);
		if (temp.gender == "�" || temp.gender == "�") {
			break;
		}
		else {
			cout << "������ ��� ���! ��� ������������ ������� ��������� ���, �� � ������� �������." << endl;
		}
	}
	return temp;
}

void welcome_mes(personal temp) {
	if (temp.style_com == "���������") {
		cout << "³��� " << temp.user_name << ", � ��� - ������� " << temp.bot_name << ".� ���� ��� ���������� � ��������� �� ����������� �� ������ � ��� ��������." << endl;
	}
	else if (temp.style_com == "������") {
		cout << "������ " << temp.user_name << ", � ���-������� " << temp.bot_name << ". � ���� ��� ���������� � �������� ��������, ��������� �� ��������, ���������." << endl;
	}
}

struct storage {
	string goods_class;
	string availability;
	string brand;
	string model;
	string color;
	double weight;
};

const int MAX_GOODS = 10;
storage goods[MAX_GOODS];

int action(personal temp) {
	char choice;


	if (temp.style_com == "���������") {
		cout << "������ �� ��� ������ ��������: " << endl;
	}
	else if (temp.style_com == "������") {
		if (temp.gender == "�") {
			cout << "��� ����� �� ��� ������ ��������: " << endl;
		}
		else if (temp.gender == "�") {
			cout << "����� ��� ����� �� ��� ������ ��������: " << endl;
		}
	}
	cout << "1 - ����� ������" << endl << "2 - ��������" << endl << "3 - ����� � ��������" << endl;
	do {
		cin >> choice;
	} while (!strchr("123", choice));
	return tolower(choice);
}

int search(personal temp, storage goods[]) {
	char choice;

	if (temp.style_com == "���������") {
		cout << "����� �� ���� ��������� ������ ��������: " << endl;
	}
	else if (temp.style_com == "������") {
		cout << "� �� ���� ���������� ������� �����: " << endl;
	}
	cout << "1 - �� ������� ������" << endl << "2 - �� ��������" << endl << "3 - �� �������" << endl << "4 - �� �������" << endl << "5 - �� ��������" << endl << "6 - �� ������������ �����" << endl << "7 - �� ��������� �����" << endl;
	do {
		cin >> choice;
	} while (!strchr("1234567", choice));
	return choice;
}

void search_by_brand(const storage temp[], const int size, string& brand, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (brand == temp[i].brand) {
			cout << "�����: " << temp[i].goods_class << endl << "������: " << temp[i].availability << endl << "�����: " << temp[i].brand << endl << "������: " << temp[i].model << endl << "����: " << temp[i].color << endl << "����: " << temp[i].weight << "�" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "���������") {
			cout << "������, ����� ������ �� �������" << endl;
		}
		else if (pers.style_com == "������") {
			if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
			else if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
		}
	}
}

void search_by_class(const storage temp[], const int size, string& goods_class, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (goods_class == temp[i].goods_class) {
			cout << "�����: " << temp[i].goods_class << endl << "������: " << temp[i].availability << endl << "�����: " << temp[i].brand << endl << "������: " << temp[i].model << endl << "����: " << temp[i].color << endl << "����: " << temp[i].weight << "�" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "���������") {
			cout << "������, ����� ������ �� �������" << endl;
		}
		else if (pers.style_com == "������") {
			if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
			else if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
		}
	}
}

void search_by_availability(const storage temp[], const int size, string& availability, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (availability == temp[i].availability) {
			cout << "�����: " << temp[i].goods_class << endl << "������: " << temp[i].availability << endl << "�����: " << temp[i].brand << endl << "������: " << temp[i].model << endl << "����: " << temp[i].color << endl << "����: " << temp[i].weight << "�" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "���������") {
			cout << "������, ����� ������ �� �������" << endl;
		}
		else if (pers.style_com == "������") {
			if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
			else if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
		}
	}
}

void search_by_model(const storage temp[], const int size, string& model, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (model == temp[i].model) {
			cout << "�����: " << temp[i].goods_class << endl << "������: " << temp[i].availability << endl << "�����: " << temp[i].brand << endl << "������: " << temp[i].model << endl << "����: " << temp[i].color << endl << "����: " << temp[i].weight << "�" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "���������") {
			cout << "������, ����� ������ �� �������" << endl;
		}
		else if (pers.style_com == "������") {
			if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
			else if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
		}
	}
}

void search_by_color(const storage temp[], const int size, string& color, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (color == temp[i].color) {
			cout << "�����: " << temp[i].goods_class << endl << "������: " << temp[i].availability << endl << "�����: " << temp[i].brand << endl << "������: " << temp[i].model << endl << "����: " << temp[i].color << endl << "����: " << temp[i].weight << "�" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "���������") {
			cout << "������, ����� ������ �� �������" << endl;
		}
		else if (pers.style_com == "������") {
			if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
			else if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
		}
	}
}

void search_by_max_weight(const storage temp[], const int size, int weight, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (weight <= temp[i].weight) {
			cout << "�����: " << temp[i].goods_class << endl << "������: " << temp[i].availability << endl << "�����: " << temp[i].brand << endl << "������: " << temp[i].model << endl << "����: " << temp[i].color << endl << "����: " << temp[i].weight << "�" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "���������") {
			cout << "������, ����� ������ �� �������" << endl;
		}
		else if (pers.style_com == "������") {
			if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
			else if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
		}
	}
}

void search_by_min_weight(const storage temp[], const int size, int weight, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (weight >= temp[i].weight) {
			cout << "�����: " << temp[i].goods_class << endl << "������: " << temp[i].availability << endl << "�����: " << temp[i].brand << endl << "������: " << temp[i].model << endl << "����: " << temp[i].color << endl << "����: " << temp[i].weight << "�" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "���������") {
			cout << "������, ����� ������ �� �������" << endl;
		}
		else if (pers.style_com == "������") {
			if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
			else if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
		}
	}
}

int problem(personal temp) {
	char choice;

	if (temp.style_com == "���������") {
		cout << "ǳ�������� � ���������(1) ��� ������� �������(2)?" << endl;
	}
	else if (temp.style_com == "������") {
		if (temp.gender == "�") {
			cout << "�������� �� ������ ��������� ��������(1) �� ������ ���� �������(2)?" << endl;
		}
		else if (temp.gender == "�") {
			cout << "��������� �� ������ ��������� ��������(1) �� ������ ���� �������(2)?" << endl;
		}
	}

	do {
		cin >> choice;
	} while (!strchr("12", choice));
	return choice;
}

void error(personal temp) {
	string feedback, mail;

	if (temp.style_com == "���������") {
		cout << "���� �����, ������� �������� � ���� ���������: " << endl;
	}
	else if (temp.style_com == "������") {
		cout << "����� �����, ���� ���� ����������: " << endl;
	}
	cin.get();
	while (true) {
		
		getline(cin, feedback);
		if (feedback.empty() || feedback[0] == '\0') {
			cout << "������ ����������� ���! �� �������� �������� ����� �����������" << endl;
			
		}
		else {
			break;
		}
	}

	if (temp.style_com == "���������") {
		cout << "����� �������� ���� ���������� �����: " << endl;
	}
	else if (temp.style_com == "������") {
		cout << "�������� �� ����� ����: " << endl;
	}

	while (true) {
		getline(cin >> ws, mail);
		if (mail.find("@") == 0) {
			cout << "������ ��� ���!" << endl;
		}
		else if (mail.find("@gmail.com") == string::npos) {
			cout << "������ ��� ���!" << endl;
		}
		else {
			break;
		}
	}
	cout << "���� ����������� �������� �� ���. ��������, ���� ���� ����������� ��������, �� ��������� ���� �� ������ " << mail << ".\n�������� �� ������." << endl;
}

void mistake(personal pers, storage temp[], const int size) {
	string search;
	int count = 0;

	if (pers.style_com == "���������") {
		cout << "���� �� ������� ������� � ���������� ������, �� ������ �� ���������. ������� ������ ������: " << endl;
	}
	else if (pers.style_com == "������") {
		if (pers.gender == "�") {
			cout << "������� ������� � ���������� ������, ����� ���� ������ ������ �� ������ ��: " << endl;
		}
		else if (pers.gender == "�") {
			cout << "������� ������� � ���������� ������, ����� ���� ������ ������ �� ������ ��: " << endl;
		}
	}
	getline(cin >> ws, search);

	for (int i = 0; i < size; i++) {
		if (search == temp[i].model) {
			cout << "�����: " << temp[i].goods_class << endl;
			cout << "����� �����: ";
			getline(cin, temp[i].goods_class);
			cout << "������: " << temp[i].availability << endl;
			cout << "����� ������: ";
			getline(cin, temp[i].availability);
			cout << "�����: " << temp[i].brand << endl;
			cout << "����� �����: ";
			getline(cin, temp[i].brand);
			cout << "������: " << temp[i].model << endl;
			cout << "���� ������: ";
			getline(cin, temp[i].model);
			cout << "����: " << temp[i].color << endl;
			cout << "����� ����: ";
			getline(cin, temp[i].color);
			cout << "����: " << temp[i].weight << "�" << endl;
			cout << "���� ����: ";
			cin >> temp[i].weight;
			cout << endl;
			return;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "���������") {
			cout << "������, ����� ������ �� �������" << endl;
		}
		else if (pers.style_com == "������") {
			if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
			else if (pers.gender == "�") {
				cout << "���, ����� �����, � ��� ������ ����" << endl;
			}
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	goods[0] = {"��������", "� � ��������", "Razer", "Blackshark V2 X (RZ04-03240100-R3M1)", "������", 240};
	goods[1] = { "��������", "� � ��������", "HyperX", "Cloud Stinger Black (4P5L7AX)", "������", 275};
	goods[2] = { "��������", "� � ��������", "Hator", "Hyperpunk 2 Black (HTA-815)", "������", 180 };
	goods[3] = { "��������", "���� � ��������", "HyperX", "Cloud Stinger 2 Core Wired (683L9AA)", "������", 250 };
	goods[4] = { "���������", "� � ��������", "Hator", "Rockfall 2 Mecha TKL Indigo USB Black (HTK-525)", "������", 975 };
	goods[5] = { "���������", "� � ��������", "HyperX", "Alloy Origins 60 HX Red RGB Black (4P5N0AA)", "������", 780 };
	goods[6] = { "���������", "� � ��������", "Razer", "Ornata V3 X UKR USB Black (RZ03-04471900-R371)", "������", 760 };
	goods[7] = { "����", "���� � ��������", "Hator", "Stellar PRO Black USB (HTM-540)", "������", 47 };
	goods[8] = { "����", "� � ��������", "HyperX", "Pulsefire Surge Black (4P5Q1AA)", "������", 60 };
	goods[9] = { "����", "� � ��������", "Razer", "Death Adder Essential 2021 Black (RZ01-03850100-R3M1)", "������", 65 };
	

	personal set = enter();
	wstring temp = wstring(set.bot_name.begin(), set.bot_name.end());
	LPCWSTR wide = temp.c_str();
	SetConsoleTitleW(wide);
	welcome_mes(set);
	char ch;
	string parameter;
	int weight;
	for (;;) {
		ch = action(set);
		switch (ch) {
			case '1': ch = search(set, goods);
				switch (ch) {
					case '1': 
						if (set.style_com == "���������") {
							cout << "������ ����� ������: ";
						}
						if (set.style_com == "������") {
							cout << "����� ����� ���� ��� ����� ������: ";
						}
						getline(cin >> ws, parameter);
						search_by_class(goods, MAX_GOODS, parameter, set);
						break;
					case '2':
						if (set.style_com == "���������") {
							cout << "������ ������: ";
						}
						if (set.style_com == "������") {
							cout << "����� ������ ���� ��� ����� ������: ";
						}
						getline(cin >> ws, parameter);
						search_by_availability(goods, MAX_GOODS, parameter, set);
						break;
					case '3':
						if (set.style_com == "���������") {
							cout << "������ ����� ������: ";
						}
						if (set.style_com == "������") {
							cout << "����� ����� ���� ��� ����� ������: ";
						}
						getline(cin >> ws, parameter);
						search_by_brand(goods, MAX_GOODS, parameter, set);
						break;
					case '4':
						if (set.style_com == "���������") {
							cout << "������ ����� �����: ";
						}
						if (set.style_com == "������") {
							cout << "����� ������ ���� ��� ����� ������: ";
						}
						getline(cin >> ws, parameter);
						search_by_model(goods, MAX_GOODS, parameter, set);
						break;
					case '5':
						if (set.style_com == "���������") {
							cout << "������ ����� �������: ";
						}
						if (set.style_com == "������") {
							cout << "����� ������ ���� ��� ����� ������: ";
						}
						getline(cin >> ws, parameter);
						search_by_color(goods, MAX_GOODS, parameter, set);
						break;
					case '6':
						if (set.style_com == "���������") {
							cout << "������ ����������� ���� �������� ������: ";
						}
						if (set.style_com == "������") {
							cout << "����� ����������� ���� ���� ��� ����� ������: ";
						}
						cin >> weight;
						search_by_max_weight(goods, MAX_GOODS, weight, set);
						break;
					case '7':
						if (set.style_com == "���������") {
							cout << "������ �������� ���� �������� ������: ";
						}
						if (set.style_com == "������") {
							cout << "����� �������� ���� ���� ��� ����� ������: ";
						}
						cin >> weight;
						search_by_min_weight(goods, MAX_GOODS, weight, set);
						break;
				}
				break;
			case '2': ch = problem(set);
				switch (ch) {
				case '1':
					error(set);
					break;
				case '2':
					mistake(set, goods, MAX_GOODS);
					break;
				}
				break;
			case '3': return 0;
		}
	}
}