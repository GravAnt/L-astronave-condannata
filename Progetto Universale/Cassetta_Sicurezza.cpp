#include "Cassetta_Sicurezza.h"
//Fatto da Roberto Carlucci reso strutturato da Samuele Pesce

Cassetta::Cassetta()
{
    comparti = new Oggetto[maxInt];
}

void Cassetta::deposita_oggetto(int codice, Interfaccia& interfaccia, Oggetti& inventario) {
    if(contenuto<maxInt) {
        if(inventario.get_luogo(inventario.get_oggetto_indice_by_codice(codice))==0) {
            comparti[contenuto]=inventario.get_oggetto(inventario.get_oggetto_indice_by_codice(codice));
            inventario.set_luogo(inventario.get_oggetto_indice_by_codice(codice),99);
            interfaccia.scrivi("Fatto\n");
            contenuto++;
        } else  {
            interfaccia.scrivi("Non ce l'hai\n");
        }
    } else{
        interfaccia.scrivi("La cassetta e' piena purtroppo\n");
    }
}

void Cassetta::mostra_contenuto(Interfaccia& interfaccia) {
    if(contenuto!=0) {
        interfaccia.scrivi("All'interno della cassetta vedo: ");
        for(int i=0;i<contenuto;i++) {
            interfaccia.scrivi_parziale( " - " );
            interfaccia.scrivi(comparti[i].get_nome());
        }
    } else interfaccia.scrivi("La cassetta di sicurezza e' vuota");
}

void Cassetta::ritira_oggetto(int codice,Interfaccia& interfaccia,Oggetti& inventario)
{
    bool trovato = false;
    if(contenuto!=0) {
        int i = 0;
        while( i < contenuto && trovato == false ){
            if(codice == comparti[i].get_codice()){
                trovato = true;
                inventario.set_luogo(inventario.get_oggetto_indice_by_codice(codice),0);
                for(int j=i;j<contenuto-1;j++) comparti[j]=comparti[j+1];
                contenuto--;
                interfaccia.scrivi("Fatto\n");
            }
            i++;
        }
    }
    if(!trovato) interfaccia.scrivi("L' oggetto richiesto non e' disponibile");
}
