#include "cub3d.h"

void    img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pix;
    int     i;

    i = img->bpp - 8;
    pix = img->addr + (y * img->line_len + x * (img->bpp / 8));
    while (i >= 0)
    {
        if (img->endian != 0)
            *pix++ = (color >> i) & 0xFF;
        else
            *pix++ = (color >> (img->bpp - 8 - i)) & 0xFF;
        i -= 8;
    }
}