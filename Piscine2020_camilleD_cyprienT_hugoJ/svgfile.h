#ifndef SVGFILE_H_INCLUDED
#define SVGFILE_H_INCLUDED

#include <string>
#include <fstream>
#include <set>

/// CODE DE MONSIEUR FERCOQ DU SEMESTRE 1

constexpr char defcol[] = "black";

class Svgfile
{
    private:
        std::string m_filename;
        std::ofstream m_ostrm;
        int m_width;
        int m_height;

        // Pour �viter les ouverture multiples
        static std::set<std::string> s_openfiles;

    public:

        Svgfile(std::string _filename = "output.svg", int _width=1000, int _height=800);
        ~Svgfile();

        void addLine(double x1, double y1, double x2, double y2, std::string color=defcol);

        void addText(double x, double y, std::string text, std::string color=defcol);
        void addText(double x, double y, double val, std::string color=defcol);

        void addGrid(double span=100.0, bool numbering=true, std::string color="lightgrey");
};

std::string makeRGB(int r, int g, int b);

void svgTest();

#endif // SVGFILE_H_INCLUDED
