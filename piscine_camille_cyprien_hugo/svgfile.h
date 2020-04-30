#ifndef SVGFILE_H_INCLUDED
#define SVGFILE_H_INCLUDED
#include <string>
#include <fstream>
#include <set>


constexpr char defcol[] = "black";

class Svgfile
{
private:

    std::string m_filename;
    std::ofstream m_ostrm;
    int m_width;
    int m_height;

    // Pour éviter les ouverture multiples
    static std::set<std::string> s_openfiles;

public:

    Svgfile(std::string _filename = "graphe.svg", int _width=1000, int _height=800);
    ~Svgfile();

    void addLine(double x1, double y1, double x2, double y2, std::string color=defcol);
    void addDisk(double x, double y, double r, std::string color);

    void addText(double x, double y, std::string text, std::string color=defcol);
    void addText(double x, double y, double val, std::string color=defcol);

    void addGrid(double span=100.0, bool numbering=true, std::string color="lightgrey");
    void svg_sommet(Svgfile &sommet);
};

std::string makeRGB(int r, int g, int b);



#endif // SVGFILE_H_INCLUDED
