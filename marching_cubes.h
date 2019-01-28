#ifndef MARCHING_CUBES_H
#define MARCHING_CUBES_H

namespace marching_cubes {
    namespace {
        struct cell_t {
            float vs[8];
            vec3_t ps[8];
        };

        const std::array<int, 256> edge_table;
        const int tri_table[256][16];
        
        vec3_t interpolate(
            float isolevel, const vec3_t& a, const vec3_t& b, 
            float alpha, float beta
        );

        void create_mesh_for_cell(
            float isolevel, const cell_t& cell,
            std::vector<vertex_t>& vs, std::vector<unsigned int>& is
        );
    }
    
    mesh_t polygonise(
        float resolution, float isolevel, VkCommandPool pool, 
        VkQueue queue, const sdf_t& sdf
    );
};

#endif
