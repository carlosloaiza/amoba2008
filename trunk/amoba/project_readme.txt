Anita: Szín megváltoztatva ;)

Zseniális... A kérdésedet - MSN-en elmondtad -  ide leírhattad volna szépen... No mindegy. Szóval:

Anita:
	"Majd nézd meg, és írj ötleteket, hogyan tudom megtudni, hogy amelyik gombra kattintottam, annak mi az i,j-je..."
Válasz:
	Mindenekelõtt megnézhetted volna az én widget-készletemet, aminek a kódja nálad van. A trükk egyébként a következõ:

A saját gomb osztályodban definiálsz vagy egy stringet, vagy két intet. Ebbe a létrehozás után az ablak belementi az aktuális gomb helyzetetét - mint ahogyan a gomb parent-jét is beállítja, tehát a gomb konstruktorának meghívása után valahol -. Ezek után ha  gomb kivált valamilyen akciót a felületeten, és meghívja az ablak bármilyen metódusát, akkor én olyan metódust hívnék, ami paraméterben egy gomb paramétert vár. Miért jó ez? Mert tudsz olyat csinálni, hogy ablak:actionFuggveny( gomb* g ) {
        cout << "ha-ha tudom, hogy kit nyomtak meg: " << g->sorindex << " , " << g->oszlopindex;
}

Mindjárt lehet lekódolom, ha lesz idõm... Ha nem, akkor rád vár a feladat... :)