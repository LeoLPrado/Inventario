#include <windows.h>
#include <string>
#include "opcoes_menu.h"

using namespace std;

LRESULT CALLBACK MenuProc(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK InserirProc(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK SimilaridadeProc(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK BuscarProc(HWND,UINT,WPARAM,LPARAM);

HWND campoNome;
HWND campoDono;
HWND campoProp;
HWND campoRaridade;
HWND campoId1;
HWND campoId2;
HWND campoPeso;
HWND campoBase;
HWND campoMin;
HWND campoIgnorar;

/* ====================== */
/* WINMAIN                */
/* ====================== */

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR,int)
{
    WNDCLASSEX wc;

    wc.cbSize=sizeof(WNDCLASSEX);
    wc.style=0;
    wc.cbClsExtra=0;
    wc.cbWndExtra=0;
    wc.hInstance=hInst;
    wc.hIcon=NULL;
    wc.hIconSm=NULL;
    wc.hCursor=LoadCursor(NULL,IDC_ARROW);
    wc.hbrBackground=GetSysColorBrush(COLOR_BTNFACE);
    wc.lpszMenuName=NULL;


    wc.lpfnWndProc=MenuProc;
    wc.lpszClassName="MenuPrincipal";
    RegisterClassEx(&wc);


    wc.lpfnWndProc=InserirProc;
    wc.lpszClassName="JanelaInserir";
    RegisterClassEx(&wc);
    
    wc.lpfnWndProc=SimilaridadeProc;
	wc.lpszClassName="JanelaSimilaridade";
	RegisterClassEx(&wc);
	
	wc.lpfnWndProc=BuscarProc;
	wc.lpszClassName="JanelaBuscar";
	RegisterClassEx(&wc);



    CreateWindow(
        "MenuPrincipal",
        "Bolsa Devoradora",
        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
        200,100,450,500,
        NULL,NULL,hInst,NULL
    );


    MSG msg;

    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}



/* ====================== */
/* MENU PRINCIPAL         */
/* ====================== */

LRESULT CALLBACK MenuProc(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {

    case WM_CREATE:

        CreateWindow("BUTTON","Inserir Item",
        WS_VISIBLE|WS_CHILD,
        100,30,220,35,
        hwnd,(HMENU)1,NULL,NULL);

        CreateWindow("BUTTON","Cadastrar Similaridade",
        WS_VISIBLE|WS_CHILD,
        100,75,220,35,
        hwnd,(HMENU)2,NULL,NULL);

        CreateWindow("BUTTON","Buscar Similares",
        WS_VISIBLE|WS_CHILD,
        100,120,220,35,
        hwnd,(HMENU)3,NULL,NULL);

        CreateWindow("BUTTON","Verificar Existencia",
        WS_VISIBLE|WS_CHILD,
        100,165,220,35,
        hwnd,(HMENU)4,NULL,NULL);

        CreateWindow("BUTTON","Listar Itens",
        WS_VISIBLE|WS_CHILD,
        100,210,220,35,
        hwnd,(HMENU)5,NULL,NULL);

        CreateWindow("BUTTON","Listar por Raridade",
        WS_VISIBLE|WS_CHILD,
        100,255,220,35,
        hwnd,(HMENU)6,NULL,NULL);

        CreateWindow("BUTTON","Contar Propriedade",
        WS_VISIBLE|WS_CHILD,
        100,300,220,35,
        hwnd,(HMENU)7,NULL,NULL);

        CreateWindow("BUTTON","Remover Menos Raros",
        WS_VISIBLE|WS_CHILD,
        100,345,220,35,
        hwnd,(HMENU)8,NULL,NULL);

        CreateWindow("BUTTON","Sair",
        WS_VISIBLE|WS_CHILD,
        100,390,220,35,
        hwnd,(HMENU)9,NULL,NULL);

        return 0;



    case WM_COMMAND:

        switch(LOWORD(wp))
        {

            case 1:

                CreateWindow(
                    "JanelaInserir",
                    "Inserir Item",
                    WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                    300,150,400,350,
                    hwnd,NULL,NULL,NULL
                );

                return 0;



            case 2:

				CreateWindow(
					 "JanelaSimilaridade",
					 "Cadastrar Similaridade",
					 WS_OVERLAPPEDWINDOW|WS_VISIBLE,
					 300,150,380,300,
					 hwnd,NULL,NULL,NULL
				);
				
				return 0;



            case 3:

				CreateWindow(
					 "JanelaBuscar",
					 "Buscar Similares",
					 WS_OVERLAPPEDWINDOW|WS_VISIBLE,
					 300,150,400,300,
					 hwnd,NULL,NULL,NULL
				);
				
				return 0;



            case 4:

                MessageBox(
                  hwnd,
                  "Opcao em construcao",
                  "Aviso",
                  MB_OK
                );

                return 0;



            case 5:
            {
                string texto="";

                if(N==0)
                    texto="Nenhum item cadastrado.";

                for(int i=0;i<N;i++)
                {
                    texto+=itens[i].nome;
                    texto+="\n";
                    texto += " - Dono: ";
                    texto+=itens[i].dono;
                    texto+="\n";
                    texto += " - Propriedade Magica: ";
                    texto+=itens[i].propriedade_magica; 
                    texto+="\n";
					texto += " - Raridade: ";
					char buffer[20];
					wsprintf(buffer,"%d",itens[i].raridade);
					texto += buffer;
					texto += "\n";
					texto += "\n";
                }

                char titulo[100];
				wsprintf(titulo, "Itens cadastrados: %d", N);
				
				MessageBox(
				    hwnd,
				    texto.c_str(),
				    titulo,
				    MB_OK
				);

                return 0;
            }



            case 6:
            case 7:
            case 8:

                MessageBox(
                  hwnd,
                  "Funcionalidade em construcao",
                  "Aviso",
                  MB_OK
                );

                return 0;



            case 9:

                DestroyWindow(hwnd);
                return 0;
        }

        return 0;



    case WM_DESTROY:

        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd,msg,wp,lp);
}




/* ====================== */
/* JANELA INSERIR ITEM    */
/* ====================== */

LRESULT CALLBACK InserirProc(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {

    case WM_CREATE:

        CreateWindow(
        "STATIC","Nome:",
        WS_VISIBLE|WS_CHILD,
        30,30,80,25,
        hwnd,NULL,NULL,NULL);

        campoNome=
        CreateWindow(
        "EDIT","",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        120,30,180,25,
        hwnd,NULL,NULL,NULL);



        CreateWindow(
        "STATIC","Dono:",
        WS_VISIBLE|WS_CHILD,
        30,70,80,25,
        hwnd,NULL,NULL,NULL);

        campoDono=
        CreateWindow(
        "EDIT","",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        120,70,180,25,
        hwnd,NULL,NULL,NULL);



        CreateWindow(
        "STATIC","Propriedade:",
        WS_VISIBLE|WS_CHILD,
        30,110,80,25,
        hwnd,NULL,NULL,NULL);

        campoProp=
        CreateWindow(
        "EDIT","",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        120,110,180,25,
        hwnd,NULL,NULL,NULL);



        CreateWindow(
        "STATIC","Raridade:",
        WS_VISIBLE|WS_CHILD,
        30,150,80,25,
        hwnd,NULL,NULL,NULL);

        campoRaridade=
        CreateWindow(
        "EDIT","",
        WS_VISIBLE|WS_CHILD|WS_BORDER,
        120,150,180,25,
        hwnd,NULL,NULL,NULL);



        CreateWindow(
        "BUTTON","Salvar",
        WS_VISIBLE|WS_CHILD,
        120,210,120,35,
        hwnd,(HMENU)100,NULL,NULL);

        return 0;



    case WM_COMMAND:

        if(LOWORD(wp)==100)
        {
            char nome[100];
            char dono[100];
            char prop[100];
            char rar[20];

            GetWindowText(campoNome,nome,100);
            GetWindowText(campoDono,dono,100);
            GetWindowText(campoProp,prop,100);
            GetWindowText(campoRaridade,rar,20);

            itens[id].id=id;
            itens[id].nome=nome;
            itens[id].dono=dono;
            itens[id].propriedade_magica=prop;
            itens[id].raridade=atoi(rar);

            id++;
            N++;

            MessageBox(
              hwnd,
              "Item inserido!",
              "Sucesso",
              MB_OK
            );

            DestroyWindow(hwnd);

            return 0;
        }

        return 0;



    case WM_DESTROY:
        return 0;
    }

    return DefWindowProc(hwnd,msg,wp,lp);
}
LRESULT CALLBACK SimilaridadeProc(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{
	switch(msg)
	{
	
		case WM_CREATE:
		
		CreateWindow("STATIC","ID 1:",
		WS_VISIBLE|WS_CHILD,
		30,30,80,25,
		hwnd,NULL,NULL,NULL);
		
		campoId1 = CreateWindow(
	    "COMBOBOX","",
	    WS_VISIBLE|WS_CHILD|CBS_DROPDOWNLIST,
	    120,30,150,200,
	    hwnd,NULL,NULL,NULL);
		
		
		CreateWindow("STATIC","ID 2:",
		WS_VISIBLE|WS_CHILD,
		30,70,80,25,
		hwnd,NULL,NULL,NULL);
		
		campoId2 = CreateWindow(
	    "COMBOBOX","",
	    WS_VISIBLE|WS_CHILD|CBS_DROPDOWNLIST,
	    120,70,150,200,
	    hwnd,NULL,NULL,NULL);
	    
	    for(int i=0; i<N; i++)
		{
		    SendMessage(campoId1, CB_ADDSTRING, 0, (LPARAM)itens[i].nome.c_str());
		    SendMessage(campoId2, CB_ADDSTRING, 0, (LPARAM)itens[i].nome.c_str());
		}
		
		
		CreateWindow("STATIC","Peso:",
		WS_VISIBLE|WS_CHILD,
		30,110,80,25,
		hwnd,NULL,NULL,NULL);
		
		campoPeso=
		CreateWindow("EDIT","",
		WS_VISIBLE|WS_CHILD|WS_BORDER,
		120,110,150,25,
		hwnd,NULL,NULL,NULL);
		
		
		CreateWindow("BUTTON","Salvar",
		WS_VISIBLE|WS_CHILD,
		120,170,120,35,
		hwnd,(HMENU)200,NULL,NULL);
		
		return 0;
		
		
		
		case WM_COMMAND:
		
		if(LOWORD(wp)==200)
		{
			char p[20];
			
			int sel1 = SendMessage(campoId1, CB_GETCURSEL, 0, 0);
			int sel2 = SendMessage(campoId2, CB_GETCURSEL, 0, 0);
			GetWindowText(campoPeso,p,20);
			
			if(sel1 == -1 || sel2 == -1)
		    {
		        MessageBox(hwnd,"Selecione os itens","Erro",MB_OK);
		        return 0;
		    }
			
			int id1 = sel1;
			int id2 = sel2;
			int peso=atoi(p);
			
			grafo[id1].push_back((Aresta){id1,id2,peso});
			grafo[id2].push_back((Aresta){id2,id1,peso});
			
			MessageBox(
				 hwnd,
				 "Similaridade cadastrada!",
				 "Sucesso",
				 MB_OK
			);
		
			DestroyWindow(hwnd);
		
			return 0;
		}
	
		return 0;
	}
	
	return DefWindowProc(hwnd,msg,wp,lp);
}
LRESULT CALLBACK BuscarProc(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{
	switch(msg)
	{
	
		case WM_CREATE:
		
		CreateWindow("STATIC","ID Base:",
		WS_VISIBLE|WS_CHILD,
		30,30,80,25,
		hwnd,NULL,NULL,NULL);
		
		campoBase = CreateWindow(
	    "COMBOBOX","",
	    WS_VISIBLE|WS_CHILD|CBS_DROPDOWNLIST,
	    120,30,150,200,
	    hwnd,NULL,NULL,NULL);
		
		
		CreateWindow("STATIC","Minimo:",
		WS_VISIBLE|WS_CHILD,
		30,70,80,25,
		hwnd,NULL,NULL,NULL);
		
		campoMin=
		CreateWindow("EDIT","",
		WS_VISIBLE|WS_CHILD|WS_BORDER,
		120,70,150,25,
		hwnd,NULL,NULL,NULL);
		
		
		CreateWindow("STATIC","Ignorar dono:",
		WS_VISIBLE|WS_CHILD,
		15,110,110,25,
		hwnd,NULL,NULL,NULL);
		
		campoIgnorar = CreateWindow(
	    "COMBOBOX","",
	    WS_VISIBLE|WS_CHILD|CBS_DROPDOWNLIST,
	    120,110,150,200,
	    hwnd,NULL,NULL,NULL);
	    
	    // itens
		for(int i=0; i<N; i++)
		{
		    SendMessage(campoBase, CB_ADDSTRING, 0, (LPARAM)itens[i].nome.c_str());
		}
		
		// donos (sem repetir)
		for(int i=0; i<N; i++)
		{
		    bool existe=false;
		
		    for(int j=0; j<i; j++)
		    {
		        if(itens[i].dono == itens[j].dono)
		            existe=true;
		    }
		
		    if(!existe)
		    {
		        SendMessage(campoIgnorar, CB_ADDSTRING, 0, (LPARAM)itens[i].dono.c_str());
		    }
		}
		
		
		CreateWindow("BUTTON","Buscar",
		WS_VISIBLE|WS_CHILD,
		120,170,120,35,
		hwnd,(HMENU)300,NULL,NULL);
		
		return 0;
		
		
		
		case WM_COMMAND:
		
		if(LOWORD(wp)==300)
		{
			char b[20],j[100];
			
			GetWindowText(campoMin,b,20);
			
			int C = SendMessage(campoBase, CB_GETCURSEL, 0, 0);
			int selDono = SendMessage(campoIgnorar, CB_GETCURSEL, 0, 0);

			SendMessage(campoIgnorar, CB_GETLBTEXT, selDono, (LPARAM)j);
			
			if(C == -1)
		    {
		        MessageBox(hwnd,"Selecione um item base","Erro",MB_OK);
		        return 0;
		    }
		
		    if(selDono == -1)
		    {
		        MessageBox(hwnd,"Selecione um dono","Erro",MB_OK);
		        return 0;
		    }

			int x=atoi(b);
			
			string texto="";
			
			list<Aresta>::iterator it;
			
			for(it=grafo[C].begin();
			it!=grafo[C].end();
			it++)
			{
				int sim=it->id2;
				
				if(it->peso>x)
				{
					if(itens[sim].dono!=j)
					{
						texto+=itens[sim].nome;
						texto+="\n";
					}
				}
			}
			
			if(texto=="")
			texto="Nenhum item encontrado.";
			
			MessageBox(
				 hwnd,
				 texto.c_str(),
				 "Similares",
				 MB_OK
			);
			
			return 0;
		}
		
		return 0;
	}	
	
	return DefWindowProc(hwnd,msg,wp,lp);
}