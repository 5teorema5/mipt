#include <iostream>
#include <cmath>
#include <vector>

#include <vtkDoubleArray.h>
#include <vtkPoints.h>
#include <vtkPointData.h>
#include <vtkTetra.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkUnstructuredGrid.h>
#include <vtkSmartPointer.h>

#include <gmsh.h>

double x_0 = 0;
double y_0 = 0;
double z_0 = 0;

using namespace std;

// Класс расчётной точки
class CalcNode {
// Класс сетки будет friend-ом точки
    friend class CalcMesh;

protected:
    // Координаты
    double x;
    double y;
    double z;
    // Некая величина, в попугаях
    double smth;
    // Скорость
    double vx;
    double vy;
    double vz;

public:
    // Конструктор по умолчанию
    CalcNode() : x(0.0), y(0.0), z(0.0), smth(0.0), vx(0.0), vy(0.0), vz(0.0) {
    }

    // Конструктор с указанием всех параметров
    CalcNode(double x, double y, double z, double smth, double vx, double vy, double vz)
            : x(x), y(y), z(z), smth(smth), vx(vx), vy(vy), vz(vz) {
    }

    // Метод отвечает за перемещение точки
    // Движемся время tau из текущего положения с текущей скоростью
    void move(double tau) {
        z -= 50 * tau;
        z_0 -= 50 * tau;
//        double ro = pow((pow((x - x_0), 2) + pow((y - y_0), 2) + pow((z - z_0), 2)), 0.5);
//        double new_ro = ro * 0.8;
//
//        double x_1 = x_0*0.9 + (double)rand() / RAND_MAX * (x_0 - x_0*0.9);
//        double y_1 = y_0*0.9 + (double)rand() / RAND_MAX * (y_0 - y_0*0.9);
//        double z_1 = z_0*0.9 + (double)rand() / RAND_MAX * (z_0 - z_0*0.9);
//        while (pow((pow((x_1 - x_0), 2) + pow((y_1 - y_0), 2) + pow((z_1 - z_0), 2)), 0.5) < ro &&
//               pow((pow((x_1 - x_0), 2) + pow((y_1 - y_0), 2) + pow((z_1 - z_0), 2)), 0.5) > new_ro) {
//            x_1 = x_0*0.9 + (double)rand() / RAND_MAX * (x_0 - x_0*0.9);
//            y_1 = y_0*0.9 + (double)rand() / RAND_MAX * (y_0 - y_0*0.9);
//            z_1 = z_0*0.9 + (double)rand() / RAND_MAX * (z_0 - z_0*0.9);
//        }
//        x = x_1;
//        y = y_1;
//        z = z_1;
//        if (x > x_0)
//            if (x_0 + 5 * tau > x)
//                x = x_0;
//            else
//                x -= 5 * tau;
//        else if (x < x_0)
//            if (x_0 - 5 * tau < x)
//                x = x_0;
//            else
//                x += 5 * tau;
//        else
//            y = y_0;
//        if (y > y_0)
//            if (y_0 + 5 * tau > y)
//                y = y_0;
//            else
//                y -= 5 * tau;
//        else if (y < y_0)
//            if (y_0 - 5 * tau < y)
//                y = y_0;
//            else
//                y += 5 * tau;
//        else
//            x = x_0;
//        if (z > z_0)
//            if (z_0 + 5 * tau > z)
//                z = z_0;
//            else
//                z -= 5 * tau;
//        else if (z < z_0)
//            if (z_0 - 5 * tau < z)
//                z = z_0;
//            else
//                z += 5 * tau;
//        else {
//            x = x_0;
//            y = y_0;
//        }
    }
};

// Класс элемента сетки
class Element {
// Класс сетки будет friend-ом и элемента тоже
// (и вообще будет нагло считать его просто структурой)
    friend class CalcMesh;

protected:
    // Индексы узлов, образующих этот элемент сетки
    unsigned long nodesIds[4];
};

// Класс расчётной сетки
class CalcMesh {
protected:
    // 3D-сетка из расчётных точек
    vector <CalcNode> nodes;
    vector <Element> elements;

public:
    // Конструктор сетки из заданного stl-файла
    CalcMesh(const std::vector<double> &nodesCoords, const std::vector <std::size_t> &tetrsPoints) {

        // Пройдём по узлам в модели gmsh
        nodes.resize(nodesCoords.size() / 3);
        for (unsigned int i = 0; i < nodesCoords.size() / 3; i++) {
            // Координаты заберём из gmsh
            double pointX = nodesCoords[i * 3];
            double pointY = nodesCoords[i * 3 + 1];
            double pointZ = nodesCoords[i * 3 + 2];
            // Модельная скалярная величина распределена как-то вот так
            double smth;
            if (pointZ > 0)
                smth = (pow(pointX, 2) + pow(pointY, 2)) * pointZ;
            else
                smth = 0;
            nodes[i] = CalcNode(pointX, pointY, pointZ, smth, 0.0, 0.0, 0.0);
        }

        // Пройдём по элементам в модели gmsh
        elements.resize(tetrsPoints.size() / 4);
        for (unsigned int i = 0; i < tetrsPoints.size() / 4; i++) {
            elements[i].nodesIds[0] = tetrsPoints[i * 4] - 1;
            elements[i].nodesIds[1] = tetrsPoints[i * 4 + 1] - 1;
            elements[i].nodesIds[2] = tetrsPoints[i * 4 + 2] - 1;
            elements[i].nodesIds[3] = tetrsPoints[i * 4 + 3] - 1;
        }
    }

    // Метод отвечает за выполнение для всей сетки шага по времени величиной tau
    void doTimeStep(double tau) {
        // По сути метод просто двигает все точки
        for (unsigned int i = 0; i < nodes.size(); i++) {
            nodes[i].move(tau);
        }
    }

    // Метод отвечает за запись текущего состояния сетки в снапшот в формате VTK
    void snapshot(unsigned int snap_number) {
        // Сетка в терминах VTK
        vtkSmartPointer <vtkUnstructuredGrid> unstructuredGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
        // Точки сетки в терминах VTK
        vtkSmartPointer <vtkPoints> dumpPoints = vtkSmartPointer<vtkPoints>::New();

        // Скалярное поле на точках сетки
        auto smth = vtkSmartPointer<vtkDoubleArray>::New();
        smth->SetName("smth");

        // Векторное поле на точках сетки
        auto vel = vtkSmartPointer<vtkDoubleArray>::New();
        vel->SetName("velocity");
        vel->SetNumberOfComponents(3);

        // Обходим все точки нашей расчётной сетки
        for (unsigned int i = 0; i < nodes.size(); i++) {
            // Вставляем новую точку в сетку VTK-снапшота
            dumpPoints->InsertNextPoint(nodes[i].x, nodes[i].y, nodes[i].z);

            // Добавляем значение векторного поля в этой точке
            double _vel[3] = {nodes[i].vx, nodes[i].vy, nodes[i].vz};
            vel->InsertNextTuple(_vel);

            // И значение скалярного поля тоже
            smth->InsertNextValue(nodes[i].smth);
        }

        // Грузим точки в сетку
        unstructuredGrid->SetPoints(dumpPoints);

        // Присоединяем векторное и скалярное поля к точкам
        unstructuredGrid->GetPointData()->AddArray(vel);
        unstructuredGrid->GetPointData()->AddArray(smth);

        // А теперь пишем, как наши точки объединены в тетраэдры
        for (unsigned int i = 0; i < elements.size(); i++) {
            auto tetra = vtkSmartPointer<vtkTetra>::New();
            tetra->GetPointIds()->SetId(0, elements[i].nodesIds[0]);
            tetra->GetPointIds()->SetId(1, elements[i].nodesIds[1]);
            tetra->GetPointIds()->SetId(2, elements[i].nodesIds[2]);
            tetra->GetPointIds()->SetId(3, elements[i].nodesIds[3]);
            unstructuredGrid->InsertNextCell(tetra->GetCellType(), tetra->GetPointIds());
        }

        // Создаём снапшот в файле с заданным именем
        string fileName = "balloon-step-" + std::to_string(snap_number) + ".vtu";
        vtkSmartPointer <vtkXMLUnstructuredGridWriter> writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
        writer->SetFileName(fileName.c_str());
        writer->SetInputData(unstructuredGrid);
        writer->Write();
    }
};

int main() {
    // Шаг точек по пространству
    double h = 4.0;
    // Шаг по времени
    double tau = 0.01;

    const unsigned int GMSH_TETR_CODE = 4;

    // Теперь придётся немного упороться:
    // (а) построением сетки средствами gmsh,
    // (б) извлечением данных этой сетки в свой код.
    gmsh::initialize();
    gmsh::model::add("balloon");

    // Считаем STL
    try {
        gmsh::merge("../balloon.stl");
    } catch (...) {
        gmsh::logger::write("Could not load STL mesh: bye!");
        gmsh::finalize();
        return -1;
    }

    // Восстановим геометрию
    double angle = 40;
    bool forceParametrizablePatches = true;
    bool includeBoundary = false;
    double curveAngle = 180;
    gmsh::model::mesh::classifySurfaces(angle * M_PI / 180., includeBoundary, forceParametrizablePatches,
                                        curveAngle * M_PI / 180.);
    gmsh::model::mesh::createGeometry();

    // Зададим объём по считанной поверхности
    std::vector <std::pair<int, int>> s;
    gmsh::model::getEntities(s, 2);
    std::vector<int> sl;
    for (auto surf: s) sl.push_back(surf.second);
    int l = gmsh::model::geo::addSurfaceLoop(sl);
    gmsh::model::geo::addVolume({l});

    gmsh::model::geo::synchronize();

    // Зададим мелкость желаемой сетки
    int f = gmsh::model::mesh::field::add("MathEval");
    gmsh::model::mesh::field::setString(f, "F", "1.5");
    gmsh::model::mesh::field::setAsBackgroundMesh(f);

    // Построим сетку
    gmsh::model::mesh::generate(3);

    // Теперь извлечём из gmsh данные об узлах сетки
    std::vector<double> nodesCoord;
    std::vector <std::size_t> nodeTags;
    std::vector<double> parametricCoord;
    gmsh::model::mesh::getNodes(nodeTags, nodesCoord, parametricCoord);

    // Найдём координаты центра шарика
    std::vector<double> nodesCoord_x;
    std::vector<double> nodesCoord_y;
    std::vector<double> nodesCoord_z;
    double sum_x = 0;
    double sum_y = 0;
    double sum_z = 0;
    for (unsigned int i = 0; i < nodesCoord.size() / 3; i++) {
        nodesCoord_x.push_back(nodesCoord[3 * i]);
        sum_x += nodesCoord[3 * i];
        nodesCoord_y.push_back(nodesCoord[3 * i + 1]);
        sum_y += nodesCoord[3 * i + 1];
        nodesCoord_z.push_back(nodesCoord[3 * i + 2]);
        sum_z += nodesCoord[3 * i + 2];
    }

    x_0 = sum_x / nodesCoord_x.size();
    y_0 = sum_y / nodesCoord_y.size();
    z_0 = sum_z / nodesCoord_z.size();

    std::cout << x_0 << ' ' << y_0 << ' ' << z_0 << '\n';

    // И данные об элементах сетки тоже извлечём, нам среди них нужны только тетраэдры, которыми залит объём
    std::vector <std::size_t> *tetrsNodesTags = nullptr;
    std::vector<int> elementTypes;
    std::vector <std::vector<std::size_t>> elementTags;
    std::vector <std::vector<std::size_t>> elementNodeTags;
    gmsh::model::mesh::getElements(elementTypes, elementTags, elementNodeTags);
    for (unsigned int i = 0; i < elementTypes.size(); i++) {
        if (elementTypes[i] != GMSH_TETR_CODE)
            continue;
        tetrsNodesTags = &elementNodeTags[i];
    }

    if (tetrsNodesTags == nullptr) {
        cout << "Can not find tetra data. Exiting." << endl;
        gmsh::finalize();
        return -2;
    }

    cout << "The model has " << nodeTags.size() << " nodes and " << tetrsNodesTags->size() / 4 << " tetrs." << endl;

    // На всякий случай проверим, что номера узлов идут подряд и без пробелов
    for (int i = 0; i < nodeTags.size(); ++i) {
        // Индексация в gmsh начинается с 1, а не с нуля. Ну штош, значит так.
        assert(i == nodeTags[i] - 1);
    }
    // И ещё проверим, что в тетраэдрах что-то похожее на правду лежит.
    assert(tetrsNodesTags->size() % 4 == 0);

    // TODO: неплохо бы полноценно данные сетки проверять, да

    CalcMesh mesh(nodesCoord, *tetrsNodesTags);

    gmsh::finalize();

    mesh.snapshot(0);

    for (unsigned int step = 1; step < 100; step++) {
        mesh.doTimeStep(tau);
        mesh.snapshot(step);
    }

    return 0;
}
