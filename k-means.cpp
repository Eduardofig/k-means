#include <cstdlib>
#include <iostream>
#include<vector>
#include<math.h>

typedef struct {
    int x, y;
}point;

typedef struct {
    point centroid;
    std::vector<point> points;
}cluster;

std::vector<cluster> k_means(std::vector<point> points, int num_centroids)
{
    std::vector<cluster> vec_cl;
    std::vector<point> centroids;
    cluster c;
    for (int i = 0; i < num_centroids; ++i) {
       c.centroid.x = rand();
       c.centroid.y = rand();
       vec_cl.push_back(c);
    };
    int c_index, c_min_dist, c_compare_dist;
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
