#ifndef VECTOR_H
#define VECTOR_H

typedef struct  s_vector
{
    float x;
    float y;
    float z;
}               t_vector;

void        vec_norm(t_vector *vec);
float       vec_lenth(t_vector *vec);
t_vector    *new_vec(float x, float y, float z);
float       vec_dot_product(t_vector *vec1, t_vector *vec2);

#endif