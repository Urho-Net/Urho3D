/*
 *
 * MIT License
   Copyright (c) 2024 Eli Aloni
   
   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:
   
   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
   
   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
 */

using System;
using System.Runtime.InteropServices;

namespace Manifold
{
    public unsafe class ManifoldNative
    {
        const string NativeImport = "Urho3D";

// Polygons
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldSimplePolygon* manifold_simple_polygon(IntPtr mem, ManifoldVec2* ps,
            int length);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldPolygons* manifold_polygons(IntPtr mem, ManifoldSimplePolygon** ps,
            int length);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_simple_polygon_length(ManifoldSimplePolygon* p);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_polygons_length(ManifoldPolygons* ps);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_polygons_simple_length(ManifoldPolygons* ps, int idx);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldVec2 manifold_simple_polygon_get_point(ManifoldSimplePolygon* p,
            int idx);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldSimplePolygon* manifold_polygons_get_simple(IntPtr mem,
            ManifoldPolygons* ps,
            int idx);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldVec2 manifold_polygons_get_point(ManifoldPolygons* ps, int simple_idx,
            int pt_idx);

// Mesh Construction
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldMeshGL* manifold_meshgl(IntPtr mem, float* vert_props, int n_verts,
            int n_props, uint* tri_verts,
            int n_tris);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldMeshGL* manifold_meshgl_w_tangents(IntPtr mem, float* vert_props,
            int n_verts, int n_props,
            uint* tri_verts, int n_tris,
            float* halfedge_tangent);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldMeshGL* manifold_get_meshgl(IntPtr mem, ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldMeshGL* manifold_meshgl_copy(IntPtr mem, ManifoldMeshGL* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldMeshGL* manifold_meshgl_merge(IntPtr mem, ManifoldMeshGL* m);


        // Manifold Vectors
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifoldVec* manifold_manifold_empty_vec(IntPtr mem);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifoldVec* manifold_manifold_vec(IntPtr mem, int sz);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_manifold_vec_reserve(ManifoldManifoldVec* ms, int sz);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_manifold_vec_length(ManifoldManifoldVec* ms);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_manifold_vec_get(IntPtr mem, ManifoldManifoldVec* ms,
            int idx);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_manifold_vec_set(ManifoldManifoldVec* ms, int idx,
            ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_manifold_vec_push_back(ManifoldManifoldVec* ms,
            ManifoldManifold* m);

// Manifold Booleans
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_boolean(IntPtr mem, ManifoldManifold* a,
            ManifoldManifold* b, ManifoldOpType op);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_batch_boolean(IntPtr mem, ManifoldManifoldVec* ms,
            ManifoldOpType op);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_union(IntPtr mem, ManifoldManifold* a,
            ManifoldManifold* b);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_difference(IntPtr mem, ManifoldManifold* a,
            ManifoldManifold* b);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_intersection(IntPtr mem, ManifoldManifold* a,
            ManifoldManifold* b);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifoldPair manifold_split(IntPtr mem_first, IntPtr mem_second,
            ManifoldManifold* a, ManifoldManifold* b);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifoldPair manifold_split_by_plane(IntPtr mem_first, IntPtr mem_second,
            ManifoldManifold* m,
            double normal_x, double normal_y,
            double normal_z, double offset);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_trim_by_plane(IntPtr mem, ManifoldManifold* m,
            double normal_x, double normal_y,
            double normal_z, double offset);


        // 3D to 2D
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldPolygons* manifold_slice(IntPtr mem, ManifoldManifold* m, double height);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldPolygons* manifold_project(IntPtr mem, ManifoldManifold* m);

// Convex Hulls
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_hull(IntPtr mem, ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_batch_hull(IntPtr mem, ManifoldManifoldVec* ms);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_hull_pts(IntPtr mem, ManifoldVec3* ps, int length);

// Manifold Transformations
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_translate(IntPtr mem, ManifoldManifold* m, double x,
            double y, double z);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_rotate(IntPtr mem, ManifoldManifold* m, double x,
            double y, double z);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_scale(IntPtr mem, ManifoldManifold* m, double x,
            double y, double z);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_transform(IntPtr mem, ManifoldManifold* m, double x1,
            double y1, double z1, double x2, double y2,
            double z2, double x3, double y3, double z3,
            double x4, double y4, double z4);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_mirror(IntPtr mem, ManifoldManifold* m, double nx,
            double ny, double nz);

        // public static extern ManifoldManifold *manifold_warp(IntPtr mem, ManifoldManifold *m,
        //                         ManifoldVec3 (*fun)(double, double, double,
        //                                             IntPtr ),
        //                         IntPtr ctx);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_smooth_by_normals(IntPtr mem, ManifoldManifold* m,
            int normalIdx);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_smooth_out(IntPtr mem, ManifoldManifold* m,
            double minSharpAngle,
            double minSmoothness);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_refine(IntPtr mem, ManifoldManifold* m, int refine);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_refine_to_length(IntPtr mem, ManifoldManifold* m,
            double length);


        // Manifold Shapes / Constructors
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_empty(IntPtr mem);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_copy(IntPtr mem, ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_tetrahedron(IntPtr mem);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_cube(IntPtr mem, double x, double y, double z,
            int center);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_cylinder(IntPtr mem, double height, double radius_low,
            double radius_high, int circular_segments,
            int center);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_sphere(IntPtr mem, double radius,
            int circular_segments);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_of_meshgl(IntPtr mem, ManifoldMeshGL* mesh);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_smooth(IntPtr mem, ManifoldMeshGL* mesh,
            int* half_edges, double* smoothness,
            int n_idxs);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_extrude(IntPtr mem, ManifoldPolygons* cs,
            double height, int slices,
            double twist_degrees, double scale_x,
            double scale_y);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_revolve(IntPtr mem, ManifoldPolygons* cs,
            int circular_segments,double revolveDegrees);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_compose(IntPtr mem, ManifoldManifoldVec* ms);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifoldVec* manifold_decompose(IntPtr mem, ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_as_original(IntPtr mem, ManifoldManifold* m);


        // Manifold Info
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_is_empty(ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldError manifold_status(ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_num_vert(ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_num_edge(ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_num_tri(ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldBox* manifold_bounding_box(IntPtr  mem, ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern double manifold_precision(ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_genus(ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldProperties manifold_get_properties(ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_get_circular_segments(double radius);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_original_id(ManifoldManifold* m);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint manifold_reserve_ids(uint n);

        // public static extern ManifoldManifold *manifold_set_properties(
        //     IntPtr mem, ManifoldManifold *m, int num_prop,
        //     void (*fun)(double *new_prop, ManifoldVec3 position, const double *old_prop,
        // IntPtr ctx),
        // IntPtr ctx);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_calculate_curvature(IntPtr  mem, ManifoldManifold* m,
            int gaussian_idx, int mean_idx);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern double manifold_min_gap(ManifoldManifold* m, ManifoldManifold* other,
            double searchLength);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldManifold* manifold_calculate_normals(IntPtr  mem, ManifoldManifold* m,
            int normal_idx,
            int min_sharp_angle);


        // CrossSection Shapes/Constructors
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection* manifold_cross_section_empty(IntPtr mem);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection* manifold_cross_section_copy(IntPtr mem,
            ManifoldCrossSection* cs);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection* manifold_cross_section_of_simple_polygon(
            IntPtr mem, ManifoldSimplePolygon* p, ManifoldFillRule fr);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection* manifold_cross_section_of_polygons(IntPtr mem,
            ManifoldPolygons* p,
            ManifoldFillRule fr);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection* manifold_cross_section_square(IntPtr mem, double x,
            double y, int center);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection* manifold_cross_section_circle(IntPtr mem, double radius,
            int circular_segments);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection* manifold_cross_section_compose(
            IntPtr mem, ManifoldCrossSectionVec* csv);

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSectionVec* manifold_cross_section_decompose(
            IntPtr mem, ManifoldCrossSection* cs);


        
        // CrossSection Vectors
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSectionVec *manifold_cross_section_empty_vec(IntPtr mem);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSectionVec *manifold_cross_section_vec(IntPtr mem, int   sz);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_cross_section_vec_reserve(ManifoldCrossSectionVec *csv,
            int   sz);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int   manifold_cross_section_vec_length(ManifoldCrossSectionVec *csv);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_vec_get(
            IntPtr mem, ManifoldCrossSectionVec *csv, int idx);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_cross_section_vec_set(ManifoldCrossSectionVec *csv, int idx,
            ManifoldCrossSection *cs);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_cross_section_vec_push_back(ManifoldCrossSectionVec *csv,
            ManifoldCrossSection *cs);
        
        
        
        // CrossSection Booleans
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_boolean(IntPtr  mem,
                                                     ManifoldCrossSection *a,
                                                     ManifoldCrossSection *b,
                                                     ManifoldOpType op);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_batch_boolean(
    IntPtr  mem, ManifoldCrossSectionVec *csv, ManifoldOpType op);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_union(IntPtr  mem,
                                                   ManifoldCrossSection *a,
                                                   ManifoldCrossSection *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_difference(
    IntPtr  mem, ManifoldCrossSection *a, ManifoldCrossSection *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_intersection(
    IntPtr  mem, ManifoldCrossSection *a, ManifoldCrossSection *b);

// CrossSection Convex Hulls
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_hull(IntPtr  mem,
                                                  ManifoldCrossSection *cs);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_batch_hull(
    IntPtr  mem, ManifoldCrossSectionVec *css);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_hull_simple_polygon(
    IntPtr  mem, ManifoldSimplePolygon *ps);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_hull_polygons(
    IntPtr  mem, ManifoldPolygons *ps);

// CrossSection Transformation
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_translate(IntPtr  mem,
                                                       ManifoldCrossSection *cs,
                                                       double x, double y);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_rotate(IntPtr  mem,
                                                    ManifoldCrossSection *cs,
                                                    double deg);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_scale(IntPtr  mem,
                                                   ManifoldCrossSection *cs,
                                                   double x, double y);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_mirror(IntPtr  mem,
                                                    ManifoldCrossSection *cs,
                                                    double ax_x, double ax_y);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_transform(IntPtr  mem,
                                                       ManifoldCrossSection *cs,
                                                       double x1, double y1,
                                                       double x2, double y2,
                                                       double x3, double y3);
// ManifoldCrossSection *manifold_cross_section_warp(
//     IntPtr  mem, ManifoldCrossSection *cs, ManifoldVec2 (*fun)(double, double));
// ManifoldCrossSection *manifold_cross_section_warp_context(
//     IntPtr  mem, ManifoldCrossSection *cs,
//     ManifoldVec2 (*fun)(double, double, IntPtr  ), IntPtr  ctx);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_simplify(IntPtr  mem,
                                                      ManifoldCrossSection *cs,
                                                      double epsilon);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldCrossSection *manifold_cross_section_offset(
    IntPtr  mem, ManifoldCrossSection *cs, double delta, ManifoldJoinType jt,
    double miter_limit, int circular_segments);

// CrossSection Info
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern double manifold_cross_section_area(ManifoldCrossSection *cs);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_cross_section_num_vert(ManifoldCrossSection *cs);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_cross_section_num_contour(ManifoldCrossSection *cs);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_cross_section_is_empty(ManifoldCrossSection *cs);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldRect *manifold_cross_section_bounds(IntPtr  mem,
                                            ManifoldCrossSection *cs);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldPolygons *manifold_cross_section_to_polygons(IntPtr  mem,
                                                     ManifoldCrossSection *cs);

// Rectangle
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldRect *manifold_rect(IntPtr  mem, double x1, double y1, double x2,
                            double y2);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldVec2 manifold_rect_min(ManifoldRect *r);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldVec2 manifold_rect_max(ManifoldRect *r);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldVec2 manifold_rect_dimensions(ManifoldRect *r);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldVec2 manifold_rect_center(ManifoldRect *r);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern double manifold_rect_scale(ManifoldRect *r);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_rect_contains_pt(ManifoldRect *r, double x, double y);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_rect_contains_rect(ManifoldRect *a, ManifoldRect *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_rect_include_pt(ManifoldRect *r, double x, double y);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldRect *manifold_rect_union(IntPtr  mem, ManifoldRect *a, ManifoldRect *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldRect *manifold_rect_transform(IntPtr  mem, ManifoldRect *r, double x1,
                                      double y1, double x2, double y2,
                                      double x3, double y3);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldRect *manifold_rect_translate(IntPtr  mem, ManifoldRect *r, double x,
                                      double y);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldRect *manifold_rect_mul(IntPtr  mem, ManifoldRect *r, double x, double y);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_rect_does_overlap_rect(ManifoldRect *a, ManifoldRect *r);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_rect_is_empty(ManifoldRect *r);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_rect_is_finite(ManifoldRect *r);

// Bounding Box
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldBox *manifold_box(IntPtr  mem, double x1, double y1, double z1, double x2,
                          double y2, double z2);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldVec3 manifold_box_min(ManifoldBox *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldVec3 manifold_box_max(ManifoldBox *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldVec3 manifold_box_dimensions(ManifoldBox *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldVec3 manifold_box_center(ManifoldBox *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern double manifold_box_scale(ManifoldBox *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_box_contains_pt(ManifoldBox *b, double x, double y, double z);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_box_contains_box(ManifoldBox *a, ManifoldBox *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_box_include_pt(ManifoldBox *b, double x, double y, double z);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldBox *manifold_box_union(IntPtr  mem, ManifoldBox *a, ManifoldBox *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldBox *manifold_box_transform(IntPtr  mem, ManifoldBox *b, double x1,
                                    double y1, double z1, double x2, double y2,
                                    double z2, double x3, double y3, double z3,
                                    double x4, double y4, double z4);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldBox *manifold_box_translate(IntPtr  mem, ManifoldBox *b, double x,
                                    double y, double z);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern ManifoldBox *manifold_box_mul(IntPtr  mem, ManifoldBox *b, double x, double y,
                              double z);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_box_does_overlap_pt(ManifoldBox *b, double x, double y, double z);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_box_does_overlap_box(ManifoldBox *a, ManifoldBox *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_box_is_finite(ManifoldBox *b);

// Static Quality Globals
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_set_min_circular_angle(double degrees);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_set_min_circular_edge_length(double length);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_set_circular_segments(int number);

// Manifold Mesh Extraction
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_meshgl_num_prop(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_meshgl_num_vert(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int manifold_meshgl_num_tri(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int   manifold_meshgl_vert_properties_length(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int   manifold_meshgl_tri_length(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int   manifold_meshgl_merge_length(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int   manifold_meshgl_run_index_length(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int   manifold_meshgl_run_original_id_length(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int   manifold_meshgl_run_transform_length(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int   manifold_meshgl_face_id_length(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int   manifold_meshgl_tangent_length(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern float *manifold_meshgl_vert_properties(IntPtr  mem, ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint  *manifold_meshgl_tri_verts(IntPtr  mem, ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint  *manifold_meshgl_merge_from_vert(IntPtr  mem, ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint  *manifold_meshgl_merge_to_vert(IntPtr  mem, ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint  *manifold_meshgl_run_index(IntPtr  mem, ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint  *manifold_meshgl_run_original_id(IntPtr  mem, ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern float *manifold_meshgl_run_transform(IntPtr  mem, ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern uint  *manifold_meshgl_face_id(IntPtr  mem, ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern float *manifold_meshgl_halfedge_tangent(IntPtr  mem, ManifoldMeshGL *m);
        
        
        // memory size
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int  manifold_manifold_size();
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int  manifold_manifold_vec_size();
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int  manifold_cross_section_size();
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int  manifold_cross_section_vec_size();
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int  manifold_simple_polygon_size();
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int  manifold_polygons_size();
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int  manifold_manifold_pair_size();
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int  manifold_meshgl_size();
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int  manifold_box_size();
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern int  manifold_rect_size();

// destruction
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_destruct_manifold(ManifoldManifold *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_destruct_manifold_vec(ManifoldManifoldVec *ms);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_destruct_cross_section(ManifoldCrossSection *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_destruct_cross_section_vec(ManifoldCrossSectionVec *csv);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_destruct_simple_polygon(ManifoldSimplePolygon *p);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_destruct_polygons(ManifoldPolygons *p);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_destruct_meshgl(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_destruct_box(ManifoldBox *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_destruct_rect(ManifoldRect *b);

// pointer free + destruction
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_delete_manifold(ManifoldManifold *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_delete_manifold_vec(ManifoldManifoldVec *ms);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_delete_cross_section(ManifoldCrossSection *cs);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_delete_cross_section_vec(ManifoldCrossSectionVec *csv);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_delete_simple_polygon(ManifoldSimplePolygon *p);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_delete_polygons(ManifoldPolygons *p);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_delete_meshgl(ManifoldMeshGL *m);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_delete_box(ManifoldBox *b);
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_delete_rect(ManifoldRect *b);

        
        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr manifold_malloc(int size);


        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_get_mesh_data_allocated(
            ManifoldManifold* m, // ManifoldManifold*
            ref double precision, // double*
            out IntPtr vertPos, // ManifoldVec3**
            out int vertPosCount, // int*
            out IntPtr triVerts, // ManifoldIVec3**
            out int triVertsCount, // int*
            out IntPtr vertNormal, // ManifoldVec3**
            out int vertNormaCount, // int*
            out IntPtr halfedgeTangent, // ManifoldVec4**
            out int halfedgeTangentCount // int*
        );

        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_get_mesh_data(
            ManifoldManifold* m, // ManifoldManifold*
            ref double precision, // double*
            ManifoldVec3* vertPos, // ManifoldVec3**
            out int vertPosCount, // int*
            ManifoldIVec3* triVerts, // ManifoldIVec3**
            out int triVertsCount, // int*
            ManifoldVec3* vertNormal, // ManifoldVec3**
            out int vertNormaCount, // int*
            ManifoldVec4* halfedgeTangent, // ManifoldVec4**
            out int halfedgeTangentCount // int*
        );


        [DllImport(NativeImport, CallingConvention = CallingConvention.Cdecl)]
        public static extern void manifold_free_mesh_data(IntPtr vertPos, IntPtr triVerts, IntPtr vertNormal,
            IntPtr halfedgeTangent);


        public unsafe static bool manifoldGetMeshData(ManifoldManifold* manifold,
            out double precision,
            out ManifoldVec3[] outVertPos,
            out int outVertPosCount,
            out ManifoldIVec3[] outTriVerts,
            out int outTriVertsCount,
            out ManifoldVec3[] outVertNormal,
            out int outVertNormaCount)
        {

            bool result = false;
            precision = 0;
            outVertPosCount = 0;
            outTriVertsCount = 0;
            outVertNormaCount = 0;
            outVertPos = null;
            outTriVerts = null;
            outVertNormal = null;
            int halfedgeTangentCount = 0;
            
            int num_vert = manifold_num_vert(manifold);
            int num_tri = manifold_num_tri(manifold);

            if (num_vert > 0 && num_tri > 0)
            {
                outVertPos = new ManifoldVec3[num_vert];
                outVertNormal = new ManifoldVec3[num_vert];
                outTriVerts = new ManifoldIVec3[num_tri];

                fixed (ManifoldVec3* vertPosPtr = &outVertPos[0])
                fixed (ManifoldVec3* outVertNormalPtr = &outVertNormal[0])
                fixed (ManifoldIVec3* outoutTriVertsPtr = &outTriVerts[0])
                {
                    manifold_get_mesh_data(
                        manifold,
                        ref precision,
                        vertPosPtr,
                        out outVertPosCount,
                        outoutTriVertsPtr,
                        out outTriVertsCount,
                        outVertNormalPtr,
                        out outVertNormaCount,
                        null,
                        out halfedgeTangentCount
                    );
                    
                    result = true;
                }
            }

            return result;
        }
    }
}