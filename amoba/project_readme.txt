Anita: Sz�n megv�ltoztatva ;)

Zseni�lis... A k�rd�sedet - MSN-en elmondtad -  ide le�rhattad volna sz�pen... No mindegy. Sz�val:

Anita:
	"Majd n�zd meg, �s �rj �tleteket, hogyan tudom megtudni, hogy amelyik gombra kattintottam, annak mi az i,j-je..."
V�lasz:
	Mindenekel�tt megn�zhetted volna az �n widget-k�szletemet, aminek a k�dja n�lad van. A tr�kk egy�bk�nt a k�vetkez�:

A saj�t gomb oszt�lyodban defini�lsz vagy egy stringet, vagy k�t intet. Ebbe a l�trehoz�s ut�n az ablak belementi az aktu�lis gomb helyzetet�t - mint ahogyan a gomb parent-j�t is be�ll�tja, teh�t a gomb konstruktor�nak megh�v�sa ut�n valahol -. Ezek ut�n ha  gomb kiv�lt valamilyen akci�t a fel�leteten, �s megh�vja az ablak b�rmilyen met�dus�t, akkor �n olyan met�dust h�vn�k, ami param�terben egy gomb param�tert v�r. Mi�rt j� ez? Mert tudsz olyat csin�lni, hogy ablak:actionFuggveny( gomb* g ) {
        cout << "ha-ha tudom, hogy kit nyomtak meg: " << g->sorindex << " , " << g->oszlopindex;
}

Mindj�rt lehet lek�dolom, ha lesz id�m... Ha nem, akkor r�d v�r a feladat... :)