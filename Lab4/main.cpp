#include "Segment.h"
#include "functions.h"

int main() {
    Segment V1(1, 2, 1.2, 4.4), V2("2.4;2", "2.8;6.6"), V3(V1);
    V1.printSegmentCoordinate("Segment V1");
    V2.printSegmentCoordinate("Segment V2");
    V3.printSegmentCoordinate("Segment V3");
    V3 = V1 + V2;
    V3.printSegmentCoordinate("V3 = V1 + V2");
    V3++;
    V3.printSegmentCoordinate("V3++");
    Point p("Enter point:");
    p.printPoint();
    cout << V3.pointBelongsSegment(p);
    return 0;
}
