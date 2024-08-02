# Chiffre de César
Un Chiffre de César universel. Ce dernier Interprète les caractères en hexadécimal (A vaut 0x0041) et les Représentes sous formes de symbole ('A' est la représentation du point de code 65). L'avantage est qu'avec cette interprétation par l'ordinateur le chiffre peut prendre en compte TOUT les caractères définit par Unicode. 
   
## Installation

```zsh
gcc -o programme César.c
```
## Usage
Lors de l'ouverture de l'exécutable ce message s'affiche :
```bash
Voulez-vous Chiffrer (1) ou Déchiffrer (2) ?
```
Quelques exemples de chiffrement (haut) et de déchiffrement (bas), décalage de 2 (modifiable) :
```bash
1
Entrez le Message à Chiffrer : 
A æ💀‹ࢢญጩ ឦᮗᰜ∑⨕𐁍    
C"è💂※更ࢤฏጫ"ឨᮙᰞ∓⨗𐁏
```
```bash
2
Entrez le Message à Déchiffrer : 
C"è💂※更ࢤฏጫ"ឨᮙᰞ∓⨗𐁏
A æ💀‹ࢢญጩ ឦᮗᰜ∑⨕𐁍
```
Remarque : certains caractères peuvent afficher un ? dans le terminal, cela signifie que le terminal ne peut pas les Représenter, en revanche il les a bien Interprété. 
