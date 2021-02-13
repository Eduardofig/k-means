#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>

typedef struct {
    int x, y;
}point;

typedef struct {
    point centroid;
    std::vector<point> points;
    int sil_coeff;
}cluster;

std::vector<cluster> k_means(std::vector<point> points, int num_centroids)
{
    int max_x = 0, max_y = 0, c_index, c_min_dist, c_compare_dist;
    for (point p : points) {
        if (p.x > max_x) {
        max_x = p.x;
        }
        if(p.y > max_y) {
            max_y = p.y;
        }
    }
    std::vector<cluster> vec_cl;
    std::vector<point> centroids;
    cluster c;
    for (int i = 0; i < num_centroids; ++i) {
       c.centroid.x = rand() % max_x;
       c.centroid.y = rand() % max_y;
       vec_cl.push_back(c);
    };
    for(point p : points) {
        c_index = 0, c_min_dist = (sqrt((p.x - vec_cl[0].centroid.x)^2 + (p.y - vec_cl[0].centroid.y)^2));
        for(int i = 0; i < vec_cl.size(); ++i) {
            c_compare_dist = sqrt((p.x - c.centroid.x)^2 + (p.y - c.centroid.y)^2) < c_min_dist;
            if(c_compare_dist < c_min_dist) {
                c_min_dist = c_compare_dist;
                c_index = i;
            };
        };
        vec_cl[c_index].points.push_back(p);
    };
    return vec_cl;
};

int main(int argc, char *argv[])
{
    return 0; 
};
