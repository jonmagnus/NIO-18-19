### Noen C++ finurligheter
- Datastrukturen `map<string,int>` i C++ tilsvarer en `dictionary` i Python med strenger som nøkler og heltallige verdier.
- `#define A B` i C++ er kjent som en macro. Det kan i mange tilfeller tenkes på som at man bytter ut `A` med `B` gjennom hele koden. 
Et eksempel på dette er `#define INF 100000000` som har omtrent samme virkning som å definere en global konstant `const int INF = 100000000;`.
Man kan også lage mer funksjonelle macroer, som f.eks. `#define max(A,B) ((A) > (B) ? (A) : (B))` som tilsvarer
```Python
def max(A,B):
	if (A > B):
		return A
	else:
		return B
```
I slike macroer brukes en annen liten finurlighet, slik som brukes her, nemlig...
- Den tertiære operatoren `A ? B : C` som egentlig er det samme som `B if A else C`.
- Macroer brukes mye for å omdøpe mye brukte konstanter (eller for å omdøpe mer overordnede funksjonaliteter i C++ som f.eks. `#define private public`), men om vi ønsker å forkorte navnene til typer bruker vi `typedef`, som når vi skriver `typedef long long ll;`, men kanskje mer relevant når man jobber med rettede grafer:
```C++
typedef pair<int,int> ii;	// Brukes for å lagre hvor kanter går med lengden på kanten.
typedef vector<ii> vii;		// Brukes for å lagre en liste med kanter som går ut av et hjørne.
typedef vector<vii> vvii;	// Brukes for å lagre alle lister over kanter som går ut av alle hjørner.
```
