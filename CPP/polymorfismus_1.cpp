#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Vozidlo {
protected:                                                       // protected
	string model;
	string znacka;
	int maxRychlost;
public:
	Vozidlo(string znacka, string model, int maxRychlost)        // konstruktor
	{
		this->znacka = znacka;
		this->model = model;
		this->maxRychlost = maxRychlost;

	}

	virtual ~Vozidlo() {};                                                  // destruktor - pokud používám poly, musím tam dat i virtual, aby se spravne volal

	virtual void nastartovat() = 0;

	virtual void getInfo() 
	{
		cout << "Znacka: " << this->znacka << ", Model: " << this->model << ", Maximalni rychlost: " << this->maxRychlost << endl;
	}
};

class Sedan : public Vozidlo {
private:
	bool matempomat;
public:

	Sedan(string znacka, string model, int maxRychlost, bool matempomat) : Vozidlo(znacka, model, maxRychlost) {
		this->matempomat = matempomat;
	}
	
	bool maTempomat() {
		return this->matempomat;
	}

	void nastartovat() override {
		cout << "Sedan " << this->model << " nastartoval bez problemu" << endl;
	}

	void getInfo() override {
		cout << "Vozidlo ma tempomat " << (this->matempomat ? "Ano" : "Ne") << endl;
	}

	~Sedan() {};

};

class SUV : public Vozidlo {
private:
	bool ctyrixctyri;
public:

	SUV(string znacka, string model, int maxRychlost, bool ctyrixctyri) : Vozidlo(znacka, model, maxRychlost) {
		this->ctyrixctyri = ctyrixctyri;
	}

	bool ma4x4() {
		return this->ctyrixctyri;
	}

	void nastartovat() override {
		cout << "SUV " << this->model << " nastartoval bez problemu" << endl;
	}

	void getInfo() override {
		cout << "Vozidlo ma pohon 4x4: " << (this->ctyrixctyri ? "Ano" : "Ne") << endl;
	}

	~SUV() {};
};


int main()
{
	Sedan* mojeAuto = new Sedan("Hyundai", "i30", 210, true);
	SUV* spatnyAuto = new SUV("Audi", "Q5", 280, true);
	Sedan* matejAuto = new Sedan("Skoda", "Fabie", 140, false);

	vector<Vozidlo*> garaz;
	garaz.push_back(mojeAuto);
	garaz.push_back(spatnyAuto);
	garaz.push_back(matejAuto);

	for (Vozidlo*& auto_ptr : garaz) {               // zobrazeni všech aut 
		auto_ptr->nastartovat();
		auto_ptr->getInfo();
	}

	for (Vozidlo* auto_ptr : garaz) {
		delete auto_ptr;
	}

	return 0;


	// Vytvo?it vektorové pole musíte proto, abyste mohl se všemi r?znými typy (Sedan, SUV) zacházet jednotn? jako s jedním typem (Vozidlo)
	// a pak na nich v cyklu snadno provád?t stejné operace, které se ale dynamicky p?izp?sobí.
}