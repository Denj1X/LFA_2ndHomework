#ifndef AFD_H_INCLUDED
#define AFD_H_INCLUDED
#include<bits/stdc++.h>

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2>& pair) const {
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};
class AFD {
private:
	int nr_st;
	std::vector<int> m_stari;
	std::string m_sigma;
	std::unordered_map<std::pair<int, std::string>, int, pair_hash> m_delta;
	int m_stareInitiala;
	int nr_finale;
	std::vector<int> m_finale;
public:
	AFD();
	int getnr() const;
	int getfin() const;
	std::vector<int> getStari()const;
	std::string getSigma() const;
	std::unordered_map<std::pair<int, std::string>, int, pair_hash> getDelta() const;
	int getStareInitiala() const;
	std::vector<int> getFinale()const;
	void setnr(const int &nr);
	void setfin(const int &fn);
	void setStari(std::vector<int> q);
	void setSigma(const std::string& sigma);
	void setDelta(std::unordered_map<std::pair<int, std::string>, int, pair_hash> delta);
	void setStareInitiala(const int& q0);
	void setFinale(std::vector<int> f);
	void citireFisier(const std::string& fisier);
	friend std::ostream& operator<<(std::ostream& f, const AFD& afd);
	std::string accepta(const std::string& cuvant);
	int verifica();
	void stergeNeaccesibile();
	int pozitieInStari(const int& stare);
	void minimizare();
	void afisareInFisier(const std::string& fisier);
};

#endif // AFD_H_INCLUDED
