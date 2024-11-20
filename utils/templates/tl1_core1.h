            uint8x16_t vec_a_{{ index }} = vld1q_u8(a + i * KK / 2 + k * 32 * 2 + {{ index }} * 16);
            uint8x16_t vec_a{{ index }}_top = vshrq_n_u8(vec_a_{{ index }}, 4);
            uint8x16_t vec_a{{ index }}_bot = vandq_u8(vec_a_{{ index }}, vec_mask);
            int8x16_t  vec_v_{{ index }}_left_tmp0 = vqtbl1q_s8(vec_lut[{{ 2 * by // 2 }} * k + {{ (4 * index) % (2 * by // 2) }}], vec_a{{ index }}_top);
            int8x16_t  vec_v_{{ index }}_left_tmp1 = vqtbl1q_s8(vec_lut[{{ 2 * by // 2 }} * k + {{ (4 * index + 1) % (2 * by // 2) }}], vec_a{{ index }}_top);
            int8x16_t  vec_v_{{ index }}_right_tmp0 = vqtbl1q_s8(vec_lut[{{ 2 * by // 2 }} * k + {{ (4 * index + 2) % (2 * by // 2) }}], vec_a{{ index }}_bot);
            int8x16_t  vec_v_{{ index }}_right_tmp1 = vqtbl1q_s8(vec_lut[{{ 2 * by // 2 }} * k + {{ (4 * index + 3) % (2 * by // 2) }}], vec_a{{ index }}_bot);
            int8x16x2_t  vec_v_left_{{ index }} = vzipq_s8(vec_v_{{ index }}_left_tmp1, vec_v_{{ index }}_left_tmp0);
            int8x16x2_t  vec_v_right_{{ index }} = vzipq_s8(vec_v_{{ index }}_right_tmp1, vec_v_{{ index }}_right_tmp0);
            vec_c[{{ (index * 2) // (by // 2) * 2 + 0 }}] += vec_v_left_{{ index }}.val[0];
            vec_c[{{ (index * 2) // (by // 2) * 2 + 0 }}] += vec_v_right_{{ index }}.val[0];
            vec_c[{{ (index * 2) // (by // 2) * 2 + 1 }}] += vec_v_left_{{ index }}.val[1];
            vec_c[{{ (index * 2) // (by // 2) * 2 + 1 }}] += vec_v_right_{{ index }}.val[1];
