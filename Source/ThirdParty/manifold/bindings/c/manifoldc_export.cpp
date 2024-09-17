// Copyright 2023 The Manifold Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifdef _MSC_VER
#define DllExport __declspec( dllexport )
#else
#define DllExport extern "C" __attribute__((visibility("default")))
#endif

#include "manifold/manifoldc.h"

#include <vector>

#include "manifold/common.h"
#include "manifold/conv.h"
#include "manifold/cross_section.h"
#include "manifold/manifold.h"
#include "manifold/types.h"


using namespace manifold;

namespace {
ManifoldManifold *level_set(
    void *mem, double (*sdf_context)(double, double, double, void *),
    ManifoldBox *bounds, double edge_length, double level, double precision,
    bool seq, void *ctx) {
  // Bind function with context argument to one without
  using namespace std::placeholders;
  std::function<double(double, double, double)> sdf =
      std::bind(sdf_context, _1, _2, _3, ctx);
  std::function<double(vec3)> fun = [sdf](vec3 v) {
    return (sdf(v.x, v.y, v.z));
  };
  return to_c(new (mem) Manifold(Manifold::LevelSet(
      fun, *from_c(bounds), edge_length, level, precision, !seq)));
}
}  // namespace

#ifdef __cplusplus
extern "C" {
#endif

DllExport ManifoldSimplePolygon *manifold_simple_polygon(void *mem, ManifoldVec2 *ps,
                                               size_t length) {
  auto vec = new (mem) std::vector<vec2>;
  for (size_t i = 0; i < length; ++i) {
    vec->push_back({ps[i].x, ps[i].y});
  }
  return to_c(vec);
}

DllExport ManifoldPolygons *manifold_polygons(void *mem, ManifoldSimplePolygon **ps,
                                    size_t length) {
  auto vec = new (mem) std::vector<SimplePolygon>;
  auto polys = reinterpret_cast<SimplePolygon **>(ps);
  for (size_t i = 0; i < length; ++i) {
    vec->push_back(*polys[i]);
  }
  return to_c(vec);
}

DllExport size_t manifold_simple_polygon_length(ManifoldSimplePolygon *p) {
  return from_c(p)->size();
}

DllExport size_t manifold_polygons_length(ManifoldPolygons *ps) {
  return from_c(ps)->size();
}

DllExport size_t manifold_polygons_simple_length(ManifoldPolygons *ps, int idx) {
  return (*from_c(ps))[idx].size();
}

DllExport ManifoldVec2 manifold_simple_polygon_get_point(ManifoldSimplePolygon *p,
                                               int idx) {
  return to_c((*from_c(p))[idx]);
}

DllExport ManifoldSimplePolygon *manifold_polygons_get_simple(void *mem,
                                                    ManifoldPolygons *ps,
                                                    int idx) {
  auto sp = (*from_c(ps))[idx];
  return to_c(new (mem) SimplePolygon(sp));
}

DllExport ManifoldVec2 manifold_polygons_get_point(ManifoldPolygons *ps, int simple_idx,
                                         int pt_idx) {
  return to_c((*from_c(ps))[simple_idx][pt_idx]);
}

DllExport ManifoldManifoldVec *manifold_manifold_empty_vec(void *mem) {
  return to_c(new (mem) ManifoldVec());
}

DllExport ManifoldManifoldVec *manifold_manifold_vec(void *mem, size_t sz) {
  return to_c(new (mem) ManifoldVec(sz));
}

DllExport void manifold_manifold_vec_reserve(ManifoldManifoldVec *ms, size_t sz) {
  from_c(ms)->reserve(sz);
}

DllExport size_t manifold_manifold_vec_length(ManifoldManifoldVec *ms) {
  return from_c(ms)->size();
}

DllExport ManifoldManifold *manifold_manifold_vec_get(void *mem, ManifoldManifoldVec *ms,
                                            int idx) {
  auto m = (*from_c(ms))[idx];
  return to_c(new (mem) Manifold(m));
}

DllExport void manifold_manifold_vec_set(ManifoldManifoldVec *ms, int idx,
                               ManifoldManifold *m) {
  (*from_c(ms))[idx] = *from_c(m);
}

DllExport void manifold_manifold_vec_push_back(ManifoldManifoldVec *ms,
                                     ManifoldManifold *m) {
  return from_c(ms)->push_back(*from_c(m));
}

DllExport ManifoldManifold *manifold_boolean(void *mem, ManifoldManifold *a,
                                   ManifoldManifold *b, ManifoldOpType op) {
  auto m = from_c(a)->Boolean(*from_c(b), from_c(op));
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_batch_boolean(void *mem, ManifoldManifoldVec *ms,
                                         ManifoldOpType op) {
  auto m = Manifold::BatchBoolean(*from_c(ms), from_c(op));
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_union(void *mem, ManifoldManifold *a,
                                 ManifoldManifold *b) {
  auto m = (*from_c(a)) + (*from_c(b));
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_difference(void *mem, ManifoldManifold *a,
                                      ManifoldManifold *b) {
  auto m = (*from_c(a)) - (*from_c(b));
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_intersection(void *mem, ManifoldManifold *a,
                                        ManifoldManifold *b) {
  auto m = (*from_c(a)) ^ (*from_c(b));
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifoldPair manifold_split(void *mem_first, void *mem_second,
                                    ManifoldManifold *a, ManifoldManifold *b) {
  auto pair = from_c(a)->Split(*from_c(b));
  auto first = new (mem_first) Manifold(pair.first);
  auto second = new (mem_second) Manifold(pair.second);
  return {to_c(first), to_c(second)};
}

DllExport ManifoldManifoldPair manifold_split_by_plane(void *mem_first, void *mem_second,
                                             ManifoldManifold *m,
                                             double normal_x, double normal_y,
                                             double normal_z, double offset) {
  auto normal = vec3(normal_x, normal_y, normal_z);
  auto pair = from_c(m)->SplitByPlane(normal, offset);
  auto first = new (mem_first) Manifold(pair.first);
  auto second = new (mem_second) Manifold(pair.second);
  return {to_c(first), to_c(second)};
}

DllExport ManifoldManifold *manifold_trim_by_plane(void *mem, ManifoldManifold *m,
                                         double normal_x, double normal_y,
                                         double normal_z, double offset) {
  auto normal = vec3(normal_x, normal_y, normal_z);
  auto trimmed = from_c(m)->TrimByPlane(normal, offset);
  return to_c(new (mem) Manifold(trimmed));
}

DllExport ManifoldPolygons *manifold_slice(void *mem, ManifoldManifold *m,
                                 double height) {
  auto poly = from_c(m)->Slice(height);
  return to_c(new (mem) Polygons(poly));
}

DllExport ManifoldPolygons *manifold_project(void *mem, ManifoldManifold *m) {
  auto poly = from_c(m)->Project();
  return to_c(new (mem) Polygons(poly));
}

DllExport ManifoldManifold *manifold_hull(void *mem, ManifoldManifold *m) {
  auto hulled = from_c(m)->Hull();
  return to_c(new (mem) Manifold(hulled));
}

DllExport ManifoldManifold *manifold_batch_hull(void *mem, ManifoldManifoldVec *ms) {
  auto hulled = Manifold::Hull(*from_c(ms));
  return to_c(new (mem) Manifold(hulled));
}

DllExport ManifoldManifold *manifold_hull_pts(void *mem, ManifoldVec3 *ps,
                                    size_t length) {
  std::vector<vec3> vec(length);
  for (size_t i = 0; i < length; ++i) {
    vec[i] = {ps[i].x, ps[i].y, ps[i].z};
  }
  auto hulled = Manifold::Hull(vec);
  return to_c(new (mem) Manifold(hulled));
}

DllExport ManifoldManifold *manifold_translate(void *mem, ManifoldManifold *m, double x,
                                     double y, double z) {
  auto v = vec3(x, y, z);
  auto translated = from_c(m)->Translate(v);
  return to_c(new (mem) Manifold(translated));
}

DllExport ManifoldManifold *manifold_rotate(void *mem, ManifoldManifold *m, double x,
                                  double y, double z) {
  auto rotated = from_c(m)->Rotate(x, y, z);
  return to_c(new (mem) Manifold(rotated));
}

DllExport ManifoldManifold *manifold_scale(void *mem, ManifoldManifold *m, double x,
                                 double y, double z) {
  auto s = vec3(x, y, z);
  auto scaled = from_c(m)->Scale(s);
  return to_c(new (mem) Manifold(scaled));
}

DllExport ManifoldManifold *manifold_transform(void *mem, ManifoldManifold *m, double x1,
                                     double y1, double z1, double x2, double y2,
                                     double z2, double x3, double y3, double z3,
                                     double x4, double y4, double z4) {
  auto mat = mat4x3(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
  auto transformed = from_c(m)->Transform(mat);
  return to_c(new (mem) Manifold(transformed));
}

DllExport ManifoldManifold *manifold_mirror(void *mem, ManifoldManifold *m, double nx,
                                  double ny, double nz) {
  auto mirrored = from_c(m)->Mirror({nx, ny, nz});
  return to_c(new (mem) Manifold(mirrored));
}

DllExport ManifoldManifold *manifold_warp(void *mem, ManifoldManifold *m,
                                ManifoldVec3 (*fun)(double, double, double,
                                                    void *),
                                void *ctx) {
  // Bind function with context argument to one without
  using namespace std::placeholders;
  std::function<ManifoldVec3(double, double, double)> f3 =
      std::bind(fun, _1, _2, _3, ctx);
  std::function<void(vec3 & v)> warp = [f3](vec3 &v) {
    v = from_c(f3(v.x, v.y, v.z));
  };
  auto warped = from_c(m)->Warp(warp);
  return to_c(new (mem) Manifold(warped));
}

DllExport ManifoldManifold *manifold_level_set(
    void *mem, double (*sdf)(double, double, double, void *),
    ManifoldBox *bounds, double edge_length, double level, double precision,
    void *ctx) {
  return level_set(mem, sdf, bounds, edge_length, level, precision, false, ctx);
}

DllExport ManifoldManifold *manifold_level_set_seq(
    void *mem, double (*sdf)(double, double, double, void *),
    ManifoldBox *bounds, double edge_length, double level, double precision,
    void *ctx) {
  return level_set(mem, sdf, bounds, edge_length, level, precision, true, ctx);
}

DllExport ManifoldManifold *manifold_smooth_by_normals(void *mem, ManifoldManifold *m,
                                             int normalIdx) {
  auto smoothed = from_c(m)->SmoothByNormals(normalIdx);
  return to_c(new (mem) Manifold(smoothed));
}

DllExport ManifoldManifold *manifold_smooth_out(void *mem, ManifoldManifold *m,
                                      double minSharpAngle,
                                      double minSmoothness) {
  auto smoothed = from_c(m)->SmoothOut(minSharpAngle, minSmoothness);
  return to_c(new (mem) Manifold(smoothed));
}

DllExport ManifoldManifold *manifold_refine(void *mem, ManifoldManifold *m, int refine) {
  auto refined = from_c(m)->Refine(refine);
  return to_c(new (mem) Manifold(refined));
}

DllExport ManifoldManifold *manifold_refine_to_length(void *mem, ManifoldManifold *m,
                                            double length) {
  auto refined = from_c(m)->RefineToLength(length);
  return to_c(new (mem) Manifold(refined));
}

DllExport ManifoldManifold *manifold_empty(void *mem) {
  return to_c(new (mem) Manifold());
}

DllExport ManifoldManifold *manifold_copy(void *mem, ManifoldManifold *m) {
  return to_c(new (mem) Manifold(*from_c(m)));
}

DllExport ManifoldManifold *manifold_tetrahedron(void *mem) {
  auto m = Manifold::Tetrahedron();
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_cube(void *mem, double x, double y, double z,
                                int center) {
  auto size = vec3(x, y, z);
  auto m = Manifold::Cube(size, center);
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_cylinder(void *mem, double height, double radius_low,
                                    double radius_high, int circular_segments,
                                    int center) {
  auto m = Manifold::Cylinder(height, radius_low, radius_high,
                              circular_segments, center);
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_sphere(void *mem, double radius,
                                  int circular_segments) {
  auto m = Manifold::Sphere(radius, circular_segments);
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldMeshGL *manifold_meshgl(void *mem, float *vert_props, size_t n_verts,
                                size_t n_props, uint32_t *tri_verts,
                                size_t n_tris) {
  auto mesh = new (mem) MeshGL();
  mesh->numProp = n_props;
  mesh->vertProperties = vector_of_array(vert_props, n_verts * n_props);
  mesh->triVerts = vector_of_array(tri_verts, n_tris * 3);
  return to_c(mesh);
}

DllExport ManifoldMeshGL *manifold_meshgl_w_tangents(void *mem, float *vert_props,
                                           size_t n_verts, size_t n_props,
                                           uint32_t *tri_verts, size_t n_tris,
                                           float *halfedge_tangent) {
  auto mesh = new (mem) MeshGL();
  mesh->numProp = n_props;
  mesh->vertProperties = vector_of_array(vert_props, n_verts * n_props);
  mesh->triVerts = vector_of_array(tri_verts, n_tris * 3);
  mesh->halfedgeTangent = vector_of_array(halfedge_tangent, n_tris * 3 * 4);
  return to_c(mesh);
}

DllExport ManifoldManifold *manifold_smooth(void *mem, ManifoldMeshGL *mesh,
                                  size_t *half_edges, double *smoothness,
                                  size_t n_edges) {
  auto smooth = std::vector<Smoothness>();
  for (size_t i = 0; i < n_edges; ++i) {
    smooth.push_back({half_edges[i], smoothness[i]});
  }
  auto m = Manifold::Smooth(*from_c(mesh), smooth);
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_of_meshgl(void *mem, ManifoldMeshGL *mesh) {
  auto m = Manifold(*from_c(mesh));
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_extrude(void *mem, ManifoldPolygons *cs,
                                   double height, int slices,
                                   double twist_degrees, double scale_x,
                                   double scale_y) {
  auto scale = vec2(scale_x, scale_y);
  auto m = Manifold::Extrude(*from_c(cs), height, slices, twist_degrees, scale);
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_revolve(void *mem, ManifoldPolygons *cs,
                                   int circular_segments) {
  auto m = Manifold::Revolve(*from_c(cs), circular_segments);
  return to_c(new (mem) Manifold(m));
}

DllExport ManifoldManifold *manifold_compose(void *mem, ManifoldManifoldVec *ms) {
  auto composed = Manifold::Compose(*from_c(ms));
  return to_c(new (mem) Manifold(composed));
}

DllExport ManifoldManifoldVec *manifold_decompose(void *mem, ManifoldManifold *m) {
  auto comps = from_c(m)->Decompose();
  return to_c(new (mem) std::vector<Manifold>(comps));
}

DllExport ManifoldMeshGL *manifold_get_meshgl(void *mem, ManifoldManifold *m) {
  auto mesh = from_c(m)->GetMeshGL();
  return to_c(new (mem) MeshGL(mesh));
}

DllExport ManifoldMeshGL *manifold_meshgl_copy(void *mem, ManifoldMeshGL *m) {
  return to_c(new (mem) MeshGL(*from_c(m)));
}

DllExport ManifoldMeshGL *manifold_meshgl_merge(void *mem, ManifoldMeshGL *m) {
  auto duplicate = new (mem) MeshGL(*from_c(m));
  if (duplicate->Merge()) {
    return to_c(duplicate);
  }
  delete duplicate;
  return m;
}

DllExport int manifold_meshgl_num_prop(ManifoldMeshGL *m) { return from_c(m)->numProp; }
DllExport int manifold_meshgl_num_vert(ManifoldMeshGL *m) { return from_c(m)->NumVert(); }
DllExport int manifold_meshgl_num_tri(ManifoldMeshGL *m) { return from_c(m)->NumTri(); }

DllExport size_t manifold_meshgl_vert_properties_length(ManifoldMeshGL *m) {
  return from_c(m)->vertProperties.size();
}

DllExport size_t manifold_meshgl_tri_length(ManifoldMeshGL *m) {
  return from_c(m)->triVerts.size();
}

DllExport size_t manifold_meshgl_merge_length(ManifoldMeshGL *m) {
  return from_c(m)->mergeFromVert.size();
}

DllExport size_t manifold_meshgl_run_index_length(ManifoldMeshGL *m) {
  return from_c(m)->runIndex.size();
}

DllExport size_t manifold_meshgl_run_original_id_length(ManifoldMeshGL *m) {
  return from_c(m)->runOriginalID.size();
}

DllExport size_t manifold_meshgl_run_transform_length(ManifoldMeshGL *m) {
  return from_c(m)->runTransform.size();
}

DllExport size_t manifold_meshgl_face_id_length(ManifoldMeshGL *m) {
  return from_c(m)->faceID.size();
}

DllExport size_t manifold_meshgl_tangent_length(ManifoldMeshGL *m) {
  return from_c(m)->halfedgeTangent.size();
}

DllExport float *manifold_meshgl_vert_properties(void *mem, ManifoldMeshGL *m) {
  return copy_data(mem, from_c(m)->vertProperties);
}

DllExport uint32_t *manifold_meshgl_tri_verts(void *mem, ManifoldMeshGL *m) {
  return copy_data(mem, from_c(m)->triVerts);
}

DllExport uint32_t *manifold_meshgl_merge_from_vert(void *mem, ManifoldMeshGL *m) {
  return copy_data(mem, from_c(m)->mergeFromVert);
}

DllExport uint32_t *manifold_meshgl_merge_to_vert(void *mem, ManifoldMeshGL *m) {
  return copy_data(mem, from_c(m)->mergeToVert);
}

DllExport uint32_t *manifold_meshgl_run_index(void *mem, ManifoldMeshGL *m) {
  return copy_data(mem, from_c(m)->runIndex);
}

DllExport uint32_t *manifold_meshgl_run_original_id(void *mem, ManifoldMeshGL *m) {
  return copy_data(mem, from_c(m)->runOriginalID);
}

DllExport float *manifold_meshgl_run_transform(void *mem, ManifoldMeshGL *m) {
  return copy_data(mem, from_c(m)->runTransform);
}

DllExport uint32_t *manifold_meshgl_face_id(void *mem, ManifoldMeshGL *m) {
  return copy_data(mem, from_c(m)->faceID);
}

DllExport float *manifold_meshgl_halfedge_tangent(void *mem, ManifoldMeshGL *m) {
  return copy_data(mem, from_c(m)->halfedgeTangent);
}

DllExport ManifoldManifold *manifold_as_original(void *mem, ManifoldManifold *m) {
  auto orig = from_c(m)->AsOriginal();
  return to_c(new (mem) Manifold(orig));
}

DllExport int manifold_original_id(ManifoldManifold *m) {
  return from_c(m)->OriginalID();
}

DllExport int manifold_is_empty(ManifoldManifold *m) { return from_c(m)->IsEmpty(); }

DllExport ManifoldError manifold_status(ManifoldManifold *m) {
  auto error = from_c(m)->Status();
  return to_c(error);
}

DllExport int manifold_num_vert(ManifoldManifold *m) { return from_c(m)->NumVert(); }
DllExport int manifold_num_edge(ManifoldManifold *m) { return from_c(m)->NumEdge(); }
DllExport int manifold_num_tri(ManifoldManifold *m) { return from_c(m)->NumTri(); }
DllExport int manifold_genus(ManifoldManifold *m) { return from_c(m)->Genus(); }

DllExport ManifoldProperties manifold_get_properties(ManifoldManifold *m) {
  return to_c(from_c(m)->GetProperties());
}

DllExport ManifoldBox *manifold_bounding_box(void *mem, ManifoldManifold *m) {
  auto box = from_c(m)->BoundingBox();
  return to_c(new (mem) Box(box));
}

DllExport double manifold_precision(ManifoldManifold *m) {
  return from_c(m)->Precision();
}

DllExport uint32_t manifold_reserve_ids(uint32_t n) { return Manifold::ReserveIDs(n); }

DllExport ManifoldManifold *manifold_set_properties(
    void *mem, ManifoldManifold *m, int num_prop,
    void (*fun)(double *new_prop, ManifoldVec3 position, const double *old_prop,
                void *ctx),
    void *ctx) {
  // Bind function with context argument to one without
  using namespace std::placeholders;
  std::function<void(double *, ManifoldVec3, const double *)> f3 =
      std::bind(fun, _1, _2, _3, ctx);
  std::function<void(double *, vec3, const double *)> f =
      [f3](double *new_prop, vec3 v, const double *old_prop) {
        return (f3(new_prop, to_c(v), old_prop));
      };
  auto man = from_c(m)->SetProperties(num_prop, f);
  return to_c(new (mem) Manifold(man));
};

DllExport ManifoldManifold *manifold_calculate_curvature(void *mem, ManifoldManifold *m,
                                               int gaussian_idx, int mean_idx) {
  auto man = from_c(m)->CalculateCurvature(gaussian_idx, mean_idx);
  return to_c(new (mem) Manifold(man));
}

DllExport double manifold_min_gap(ManifoldManifold *m, ManifoldManifold *other,
                        double searchLength) {
  return from_c(m)->MinGap(*from_c(other), searchLength);
}

DllExport ManifoldManifold *manifold_calculate_normals(void *mem, ManifoldManifold *m,
                                             int normal_idx,
                                             int min_sharp_angle) {
  auto man = from_c(m)->CalculateNormals(normal_idx, min_sharp_angle);
  return to_c(new (mem) Manifold(man));
}

// Static Quality Globals

DllExport void manifold_set_min_circular_angle(double degrees) {
  Quality::SetMinCircularAngle(degrees);
}

DllExport void manifold_set_min_circular_edge_length(double length) {
  Quality::SetMinCircularEdgeLength(length);
}

DllExport void manifold_set_circular_segments(int number) {
  Quality::SetCircularSegments(number);
}

DllExport int manifold_get_circular_segments(double radius) {
  return Quality::GetCircularSegments(radius);
}

// memory size
DllExport size_t manifold_cross_section_size() { return sizeof(CrossSection); }
DllExport size_t manifold_cross_section_vec_size() {
  return sizeof(std::vector<CrossSection>);
}
DllExport size_t manifold_simple_polygon_size() { return sizeof(SimplePolygon); }
DllExport size_t manifold_polygons_size() { return sizeof(Polygons); }
DllExport size_t manifold_manifold_size() { return sizeof(Manifold); }
DllExport size_t manifold_manifold_vec_size() { return sizeof(std::vector<Manifold>); }
DllExport size_t manifold_manifold_pair_size() { return sizeof(ManifoldManifoldPair); }
DllExport size_t manifold_meshgl_size() { return sizeof(MeshGL); }
DllExport size_t manifold_box_size() { return sizeof(Box); }
DllExport size_t manifold_rect_size() { return sizeof(Rect); }

// pointer free + destruction
DllExport void manifold_delete_cross_section(ManifoldCrossSection *c) {
  delete from_c(c);
}
DllExport void manifold_delete_cross_section_vec(ManifoldCrossSectionVec *csv) {
  delete from_c(csv);
}
DllExport void manifold_delete_simple_polygon(ManifoldSimplePolygon *p) {
  delete from_c(p);
}
DllExport void manifold_delete_polygons(ManifoldPolygons *p) { delete from_c(p); }
DllExport void manifold_delete_manifold(ManifoldManifold *m) { delete from_c(m); }
DllExport void manifold_delete_manifold_vec(ManifoldManifoldVec *ms) {
  delete from_c(ms);
}
DllExport void manifold_delete_meshgl(ManifoldMeshGL *m) { delete from_c(m); }
DllExport void manifold_delete_box(ManifoldBox *b) { delete from_c(b); }
DllExport void manifold_delete_rect(ManifoldRect *r) { delete from_c(r); }

// destruction
DllExport void manifold_destruct_cross_section(ManifoldCrossSection *cs) {
  from_c(cs)->~CrossSection();
}
DllExport void manifold_destruct_cross_section_vec(ManifoldCrossSectionVec *csv) {
  from_c(csv)->~CrossSectionVec();
}
DllExport void manifold_destruct_simple_polygon(ManifoldSimplePolygon *p) {
  from_c(p)->~SimplePolygon();
}
DllExport void manifold_destruct_polygons(ManifoldPolygons *p) { from_c(p)->~Polygons(); }
DllExport void manifold_destruct_manifold(ManifoldManifold *m) { from_c(m)->~Manifold(); }
DllExport void manifold_destruct_manifold_vec(ManifoldManifoldVec *ms) {
  from_c(ms)->~ManifoldVec();
}
DllExport void manifold_destruct_meshgl(ManifoldMeshGL *m) { from_c(m)->~MeshGL(); }
DllExport void manifold_destruct_box(ManifoldBox *b) { from_c(b)->~Box(); }
DllExport void manifold_destruct_rect(ManifoldRect *r) { from_c(r)->~Rect(); }


/******************************************************************/
// TBD elix22 , my functions
/******************************************************************/
DllExport ManifoldMesh *manifold_get_mesh(void *mem, ManifoldManifold *m) {
  auto mesh = from_c(m)->GetMesh();
  return to_c(new (mem) Mesh(mesh));
}



DllExport void manifold_get_mesh_data(ManifoldManifold *m,
                                      double *precision,
                                      ManifoldVec3 **vertPos,
                                      int *vertPosCount,
                                      ManifoldIVec3 **triVerts ,
                                      int *triVertsCount,
                                      ManifoldVec3 **vertNormal,
                                      int *vertNormaCount,
                                      ManifoldVec4 ** halfedgeTangent,
                                      int *halfedgeTangentCount) {

  *vertPosCount = 0;
  *triVertsCount = 0;
  *vertNormaCount=0;
  *halfedgeTangentCount = 0;

  auto mesh = from_c(m)->GetMesh();

  *precision = mesh.precision;

  size_t vertPosSize = mesh.vertPos.size();
  if (vertPosSize > 0) {
    *vertPos = (ManifoldVec3 *)malloc(vertPosSize * sizeof(ManifoldVec3));
    for (int i = 0; i < vertPosSize; i++) {
      (*vertPos)[i] = {mesh.vertPos[i].x, mesh.vertPos[i].y, mesh.vertPos[i].z};
    }
    *vertPosCount = vertPosSize;
  }

  size_t triVertsSize = mesh.triVerts.size();
  if (triVertsSize) {
    *triVerts = (ManifoldIVec3 *)malloc(triVertsSize * sizeof(ManifoldIVec3));
    for (int i = 0; i < triVertsSize; i++) {
      (*triVerts)[i] = {mesh.triVerts[i].x, mesh.triVerts[i].y,
                      mesh.triVerts[i].z};
    }
    *triVertsCount = triVertsSize;
  }

  size_t vertNormalSize = mesh.vertNormal.size();
  if (vertNormalSize > 0) {
    *vertNormal = (ManifoldVec3 *)malloc(vertNormalSize * sizeof(ManifoldVec3));
    for (int i = 0; i < vertNormalSize; i++) {
      (*vertNormal)[i] = {mesh.vertNormal[i].x, mesh.vertNormal[i].y,
                        mesh.vertNormal[i].z};
    }
    *vertNormaCount = vertNormalSize;
  }

  size_t halfedgeTangentSize = mesh.halfedgeTangent.size();
  if (halfedgeTangentSize > 0) {
        *halfedgeTangent = (ManifoldVec4 *)malloc(halfedgeTangentSize * sizeof(ManifoldVec4));
    for (int i = 0; i < halfedgeTangentSize; i++) {
      (*halfedgeTangent)[i] = {mesh.halfedgeTangent[i].x, mesh.halfedgeTangent[i].y,
                        mesh.halfedgeTangent[i].z,mesh.halfedgeTangent[i].w};
    }
     *halfedgeTangentCount = halfedgeTangentSize;
  }
}

// Must be called to free all alloctaed data from manifold_get_mesh_data()
DllExport void manifold_free_mesh_data(ManifoldVec3 *vertPos,ManifoldIVec3 *triVerts,ManifoldVec3 *vertNormal,ManifoldVec4 * halfedgeTangent)
{
    free(vertPos);
    free(triVerts);
    free(vertNormal);
    free(halfedgeTangent);
}

DllExport void manifold_get_mesh_data2(ManifoldManifold *m,
                                      double *precision,
                                      ManifoldVec3 *vertPos,
                                      int *vertPosCount,
                                      ManifoldIVec3 *triVerts ,
                                      int *triVertsCount,
                                      ManifoldVec3 *vertNormal,
                                      int *vertNormaCount,
                                      ManifoldVec4 * halfedgeTangent,
                                      int *halfedgeTangentCount)
{
  *vertPosCount = 0;
  *triVertsCount = 0;
  *vertNormaCount=0;
  *halfedgeTangentCount = 0;

  auto mesh = from_c(m)->GetMesh();

  *precision = mesh.precision;

  size_t vertPosSize = mesh.vertPos.size();
  *vertPosCount = vertPosSize;
  if (vertPosSize > 0 && vertPos != nullptr) {
    for (int i = 0; i < vertPosSize; i++) {
      (vertPos)[i] = {mesh.vertPos[i].x, mesh.vertPos[i].y, mesh.vertPos[i].z};
    }
    
  }

  size_t triVertsSize = mesh.triVerts.size();
  *triVertsCount = triVertsSize;
  if (triVertsSize && triVerts != nullptr) {
    for (int i = 0; i < triVertsSize; i++) {
      (triVerts)[i] = {mesh.triVerts[i].x, mesh.triVerts[i].y,
                      mesh.triVerts[i].z};
    }
  }

  size_t vertNormalSize = mesh.vertNormal.size();
   *vertNormaCount = vertNormalSize;
  if (vertNormalSize > 0 && vertNormal != nullptr) {
    for (int i = 0; i < vertNormalSize; i++) {
      (vertNormal)[i] = {mesh.vertNormal[i].x, mesh.vertNormal[i].y,
                        mesh.vertNormal[i].z};
    }
  }

  size_t halfedgeTangentSize = mesh.halfedgeTangent.size();
  *halfedgeTangentCount = halfedgeTangentSize;
  if (halfedgeTangentSize > 0 && halfedgeTangent != nullptr) {
    for (int i = 0; i < halfedgeTangentSize; i++) {
      (halfedgeTangent)[i] = {mesh.halfedgeTangent[i].x, mesh.halfedgeTangent[i].y,
                        mesh.halfedgeTangent[i].z,mesh.halfedgeTangent[i].w};
    }
  }
}

DllExport void * manifold_malloc(size_t size)
{
  return malloc(size);
}

DllExport void manifold_free(void * mem)
{
   free(mem);
}

#ifdef __cplusplus
}
#endif
