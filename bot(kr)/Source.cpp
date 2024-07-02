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

	cout << "Введіть як мені називати вас: ";
	getline(cin, temp.user_name);
	cout << "Введіть як ви будете називати мене: ";
	getline(cin, temp.bot_name);
	while (true) {
		cout << "Оберіть стиль спілкування з вами(офіційний/дружній): ";
		getline(cin, temp.style_com);
		if (temp.style_com == "офіційний" || temp.style_com == "дружній") {
			break;
		}
		else {
			cout << "Введіть вірні дані! Або дотримуйтесь точного написання слів, як в поданих варінтах." << endl;
		}
	}
	while (true) {
		cout << "Оберіть свою стать(М/Ж): ";
		getline(cin, temp.gender);
		if (temp.gender == "М" || temp.gender == "Ж") {
			break;
		}
		else {
			cout << "Введіть вірні дані! Або дотримуйтесь точного написання слів, як в поданих варінтах." << endl;
		}
	}
	return temp;
}

void welcome_mes(personal temp) {
	if (temp.style_com == "офіційний") {
		cout << "Вітаю " << temp.user_name << ", я бот - помічник " << temp.bot_name << ".Я буду вам допомагити з питаннями та складнощами які будуть у вас виникати." << endl;
	}
	else if (temp.style_com == "дружній") {
		cout << "Здоров " << temp.user_name << ", я бот-помічник " << temp.bot_name << ". Я буду тобі допомагити зі всілякими траблами, питаннями та запитами, звертайся." << endl;
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


	if (temp.style_com == "офіційний") {
		cout << "Оберіть дію яку хочете виконати: " << endl;
	}
	else if (temp.style_com == "дружній") {
		if (temp.gender == "М") {
			cout << "Бро обери дію яку хочешь виконати: " << endl;
		}
		else if (temp.gender == "Ж") {
			cout << "Гарна леді обери дію яку хочешь виконати: " << endl;
		}
	}
	cout << "1 - пошук товарів" << endl << "2 - допомога" << endl << "3 - вихід з програми" << endl;
	do {
		cin >> choice;
	} while (!strchr("123", choice));
	return tolower(choice);
}

int search(personal temp, storage goods[]) {
	char choice;

	if (temp.style_com == "офіційний") {
		cout << "Пошук за яким праметром хочете виконати: " << endl;
	}
	else if (temp.style_com == "дружній") {
		cout << "А за яким параметром зробити пошук: " << endl;
	}
	cout << "1 - за классом товару" << endl << "2 - за наявністю" << endl << "3 - за брендом" << endl << "4 - за моделлю" << endl << "5 - за кольором" << endl << "6 - за максимальною вагою" << endl << "7 - за мінімальною вагою" << endl;
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
			cout << "Класс: " << temp[i].goods_class << endl << "Статус: " << temp[i].availability << endl << "Бренд: " << temp[i].brand << endl << "Модель: " << temp[i].model << endl << "Колір: " << temp[i].color << endl << "Вага: " << temp[i].weight << "г" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "офіційний") {
			cout << "Нажаль, нічого знайти не вдалось" << endl;
		}
		else if (pers.style_com == "дружній") {
			if (pers.gender == "М") {
				cout << "Блін, сорян чувак, в нас такого немає" << endl;
			}
			else if (pers.gender == "Ж") {
				cout << "Блін, сорян чувіха, в нас такого немає" << endl;
			}
		}
	}
}

void search_by_class(const storage temp[], const int size, string& goods_class, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (goods_class == temp[i].goods_class) {
			cout << "Класс: " << temp[i].goods_class << endl << "Статус: " << temp[i].availability << endl << "Бренд: " << temp[i].brand << endl << "Модель: " << temp[i].model << endl << "Колір: " << temp[i].color << endl << "Вага: " << temp[i].weight << "г" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "офіційний") {
			cout << "Нажаль, нічого знайти не вдалось" << endl;
		}
		else if (pers.style_com == "дружній") {
			if (pers.gender == "М") {
				cout << "Блін, сорян чувак, в нас такого немає" << endl;
			}
			else if (pers.gender == "Ж") {
				cout << "Блін, сорян чувіха, в нас такого немає" << endl;
			}
		}
	}
}

void search_by_availability(const storage temp[], const int size, string& availability, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (availability == temp[i].availability) {
			cout << "Класс: " << temp[i].goods_class << endl << "Статус: " << temp[i].availability << endl << "Бренд: " << temp[i].brand << endl << "Модель: " << temp[i].model << endl << "Колір: " << temp[i].color << endl << "Вага: " << temp[i].weight << "г" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "офіційний") {
			cout << "Нажаль, нічого знайти не вдалось" << endl;
		}
		else if (pers.style_com == "дружній") {
			if (pers.gender == "М") {
				cout << "Блін, сорян чувак, в нас такого немає" << endl;
			}
			else if (pers.gender == "Ж") {
				cout << "Блін, сорян чувіха, в нас такого немає" << endl;
			}
		}
	}
}

void search_by_model(const storage temp[], const int size, string& model, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (model == temp[i].model) {
			cout << "Класс: " << temp[i].goods_class << endl << "Статус: " << temp[i].availability << endl << "Бренд: " << temp[i].brand << endl << "Модель: " << temp[i].model << endl << "Колір: " << temp[i].color << endl << "Вага: " << temp[i].weight << "г" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "офіційний") {
			cout << "Нажаль, нічого знайти не вдалось" << endl;
		}
		else if (pers.style_com == "дружній") {
			if (pers.gender == "М") {
				cout << "Блін, сорян чувак, в нас такого немає" << endl;
			}
			else if (pers.gender == "Ж") {
				cout << "Блін, сорян чувіха, в нас такого немає" << endl;
			}
		}
	}
}

void search_by_color(const storage temp[], const int size, string& color, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (color == temp[i].color) {
			cout << "Класс: " << temp[i].goods_class << endl << "Статус: " << temp[i].availability << endl << "Бренд: " << temp[i].brand << endl << "Модель: " << temp[i].model << endl << "Колір: " << temp[i].color << endl << "Вага: " << temp[i].weight << "г" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "офіційний") {
			cout << "Нажаль, нічого знайти не вдалось" << endl;
		}
		else if (pers.style_com == "дружній") {
			if (pers.gender == "М") {
				cout << "Блін, сорян чувак, в нас такого немає" << endl;
			}
			else if (pers.gender == "Ж") {
				cout << "Блін, сорян чувіха, в нас такого немає" << endl;
			}
		}
	}
}

void search_by_max_weight(const storage temp[], const int size, int weight, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (weight <= temp[i].weight) {
			cout << "Класс: " << temp[i].goods_class << endl << "Статус: " << temp[i].availability << endl << "Бренд: " << temp[i].brand << endl << "Модель: " << temp[i].model << endl << "Колір: " << temp[i].color << endl << "Вага: " << temp[i].weight << "г" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "офіційний") {
			cout << "Нажаль, нічого знайти не вдалось" << endl;
		}
		else if (pers.style_com == "дружній") {
			if (pers.gender == "М") {
				cout << "Блін, сорян чувак, в нас такого немає" << endl;
			}
			else if (pers.gender == "Ж") {
				cout << "Блін, сорян чувіха, в нас такого немає" << endl;
			}
		}
	}
}

void search_by_min_weight(const storage temp[], const int size, int weight, personal pers) {
	int count = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		if (weight >= temp[i].weight) {
			cout << "Класс: " << temp[i].goods_class << endl << "Статус: " << temp[i].availability << endl << "Бренд: " << temp[i].brand << endl << "Модель: " << temp[i].model << endl << "Колір: " << temp[i].color << endl << "Вага: " << temp[i].weight << "г" << endl;
			count -= 1;
			cout << endl;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "офіційний") {
			cout << "Нажаль, нічого знайти не вдалось" << endl;
		}
		else if (pers.style_com == "дружній") {
			if (pers.gender == "М") {
				cout << "Блін, сорян чувак, в нас такого немає" << endl;
			}
			else if (pers.gender == "Ж") {
				cout << "Блін, сорян чувіха, в нас такого немає" << endl;
			}
		}
	}
}

int problem(personal temp) {
	char choice;

	if (temp.style_com == "офіційний") {
		cout << "Зіткнулися з проблемою(1) або знайшли помилку(2)?" << endl;
	}
	else if (temp.style_com == "дружній") {
		if (temp.gender == "М") {
			cout << "Натрапив на якийсь неприємний моментик(1) чи помітив щось підозріле(2)?" << endl;
		}
		else if (temp.gender == "Ж") {
			cout << "Натрапила на якийсь неприємний моментик(1) чи помітилі щось підозріле(2)?" << endl;
		}
	}

	do {
		cin >> choice;
	} while (!strchr("12", choice));
	return choice;
}

void error(personal temp) {
	string feedback, mail;

	if (temp.style_com == "офіційний") {
		cout << "Будь ласка, опишіть проблему з якою зіткнулися: " << endl;
	}
	else if (temp.style_com == "дружній") {
		cout << "Опиши трабл, який тебе потурбував: " << endl;
	}
	cin.get();
	while (true) {
		
		getline(cin, feedback);
		if (feedback.empty() || feedback[0] == '\0') {
			cout << "Введіть повідомдення дані! Ви неможете віправити пусте повідомлення" << endl;
			
		}
		else {
			break;
		}
	}

	if (temp.style_com == "офіційний") {
		cout << "Також напишіть свою електронну пошту: " << endl;
	}
	else if (temp.style_com == "дружній") {
		cout << "Начіркай ще пошту свою: " << endl;
	}

	while (true) {
		getline(cin >> ws, mail);
		if (mail.find("@") == 0) {
			cout << "Введіть вірні дані!" << endl;
		}
		else if (mail.find("@gmail.com") == string::npos) {
			cout << "Введіть вірні дані!" << endl;
		}
		else {
			break;
		}
	}
	cout << "Ваше повідомлення передано до тех. підтримки, якщо ваше повідомлення схвалять, ми відправимо лист на адресу " << mail << ".\nСлідкуйте за поштою." << endl;
}

void mistake(personal pers, storage temp[], const int size) {
	string search;
	int count = 0;

	if (pers.style_com == "офіційний") {
		cout << "Якщо ви знайщли помилку в параметрах товару, ви можете її виправити. Впишіть модель товару: " << endl;
	}
	else if (pers.style_com == "дружній") {
		if (pers.gender == "М") {
			cout << "Знайшов помилку в параметрах товарів, впиши сюди модель товару та ліквідуй її: " << endl;
		}
		else if (pers.gender == "Ж") {
			cout << "Знайшла помилку в параметрах товарів, впиши сюди модель товару та ліквідуй її: " << endl;
		}
	}
	getline(cin >> ws, search);

	for (int i = 0; i < size; i++) {
		if (search == temp[i].model) {
			cout << "Класс: " << temp[i].goods_class << endl;
			cout << "Новий класс: ";
			getline(cin, temp[i].goods_class);
			cout << "Статус: " << temp[i].availability << endl;
			cout << "Новий статус: ";
			getline(cin, temp[i].availability);
			cout << "Бренд: " << temp[i].brand << endl;
			cout << "Новий бренд: ";
			getline(cin, temp[i].brand);
			cout << "Модель: " << temp[i].model << endl;
			cout << "Нова модель: ";
			getline(cin, temp[i].model);
			cout << "Колір: " << temp[i].color << endl;
			cout << "Новий колір: ";
			getline(cin, temp[i].color);
			cout << "Вага: " << temp[i].weight << "г" << endl;
			cout << "Нова вага: ";
			cin >> temp[i].weight;
			cout << endl;
			return;
		}
		count += 1;
	}
	if (count == 10) {
		if (pers.style_com == "офіційний") {
			cout << "Нажаль, нічого знайти не вдалось" << endl;
		}
		else if (pers.style_com == "дружній") {
			if (pers.gender == "М") {
				cout << "Блін, сорян чувак, в нас такого немає" << endl;
			}
			else if (pers.gender == "Ж") {
				cout << "Блін, сорян чувіха, в нас такого немає" << endl;
			}
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	goods[0] = {"Гарнітура", "Є в наявності", "Razer", "Blackshark V2 X (RZ04-03240100-R3M1)", "Чорний", 240};
	goods[1] = { "Гарнітура", "Є в наявності", "HyperX", "Cloud Stinger Black (4P5L7AX)", "Чорний", 275};
	goods[2] = { "Гарнітура", "Є в наявності", "Hator", "Hyperpunk 2 Black (HTA-815)", "Чорний", 180 };
	goods[3] = { "Гарнітура", "Немає в наявності", "HyperX", "Cloud Stinger 2 Core Wired (683L9AA)", "Чорний", 250 };
	goods[4] = { "Клавіатура", "Є в наявності", "Hator", "Rockfall 2 Mecha TKL Indigo USB Black (HTK-525)", "Чорний", 975 };
	goods[5] = { "Клавіатура", "Є в наявності", "HyperX", "Alloy Origins 60 HX Red RGB Black (4P5N0AA)", "Чорний", 780 };
	goods[6] = { "Клавіатура", "Є в наявності", "Razer", "Ornata V3 X UKR USB Black (RZ03-04471900-R371)", "Чорний", 760 };
	goods[7] = { "Миша", "Немає в наявності", "Hator", "Stellar PRO Black USB (HTM-540)", "Чорний", 47 };
	goods[8] = { "Миша", "Є в наявності", "HyperX", "Pulsefire Surge Black (4P5Q1AA)", "Чорний", 60 };
	goods[9] = { "Миша", "Є в наявності", "Razer", "Death Adder Essential 2021 Black (RZ01-03850100-R3M1)", "Чорний", 65 };
	

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
						if (set.style_com == "офіційний") {
							cout << "Введіть назву классу: ";
						}
						if (set.style_com == "дружній") {
							cout << "Введи класс речі яку хочеш знайти: ";
						}
						getline(cin >> ws, parameter);
						search_by_class(goods, MAX_GOODS, parameter, set);
						break;
					case '2':
						if (set.style_com == "офіційний") {
							cout << "Введіть статус: ";
						}
						if (set.style_com == "дружній") {
							cout << "Введи статус речі яку хочеш знайти: ";
						}
						getline(cin >> ws, parameter);
						search_by_availability(goods, MAX_GOODS, parameter, set);
						break;
					case '3':
						if (set.style_com == "офіційний") {
							cout << "Введіть назву бренду: ";
						}
						if (set.style_com == "дружній") {
							cout << "Введи бренд речі яку хочеш знайти: ";
						}
						getline(cin >> ws, parameter);
						search_by_brand(goods, MAX_GOODS, parameter, set);
						break;
					case '4':
						if (set.style_com == "офіційний") {
							cout << "Введіть назву моделі: ";
						}
						if (set.style_com == "дружній") {
							cout << "Введи модель речі яку хочеш знайти: ";
						}
						getline(cin >> ws, parameter);
						search_by_model(goods, MAX_GOODS, parameter, set);
						break;
					case '5':
						if (set.style_com == "офіційний") {
							cout << "Введіть назву кольору: ";
						}
						if (set.style_com == "дружній") {
							cout << "Введи кольор речі яку хочеш знайти: ";
						}
						getline(cin >> ws, parameter);
						search_by_color(goods, MAX_GOODS, parameter, set);
						break;
					case '6':
						if (set.style_com == "офіційний") {
							cout << "Введіть максимальну вагу шуканого товару: ";
						}
						if (set.style_com == "дружній") {
							cout << "Введи максимальну вагу речі яку хочеш знайти: ";
						}
						cin >> weight;
						search_by_max_weight(goods, MAX_GOODS, weight, set);
						break;
					case '7':
						if (set.style_com == "офіційний") {
							cout << "Введіть мінімальну вагу шуканого товару: ";
						}
						if (set.style_com == "дружній") {
							cout << "Введи мінімальну вагу речі яку хочеш знайти: ";
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