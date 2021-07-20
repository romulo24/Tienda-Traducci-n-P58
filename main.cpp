#include "principal.h"
#include<QTranslator>
#include <QApplication>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Objeto para manejar las traducciones
       QTranslator traducion;
       // Solicitando al usuario que seleccione un idioma
         QStringList idiomas;
        idiomas << "Chino" << "Alemán" << "Español";
        QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                      "Idioma",
                                      "Seleccione un idioma",
                                      idiomas);
        // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
            if (idiomaSeleccionado == "Chino"){
                traducion.load(":/Salario_ch_CH.qm");
            }else if (idiomaSeleccionado == "Alemán"){
                traducion.load(":/Salario_al_GR.qm");
            }
            // Si es diferente de español, se instala la traducción en TODA la aplicación
            if (idiomaSeleccionado != "Español"){
                a.installTranslator(&traducion);
            }

    Principal w;
    w.show();

    return a.exec();
}
