/*This function calculates the formula of the mandelbrot*/
/*void	mandelbrot(t_img *img, int x, int y, int color)
{
	
	double		rmin;
	double		rmax;
	double		imin;
	double		imax;
	double		re_fract;
	double		im_fract;
	double		re_cord;
	double		im_cord;
	char		b_veric;
	double		re_Z;
	double		im_Z;
	double		re_C;
	double		im_C;
	double		re2_Z;   
	double		im2_Z;
	unsigned	n;
	double		tmp;

	  im_C = -0.0;
	re_C = 0.0;
	rmin = -2.0;
	rmax = 2.0;
	imin = -2.0;
	imax = imin+(rmax-rmin)*W_HEIGHT/W_WIDTH;
	re_fract = (rmax-rmin)/(W_WIDTH-1);
	im_fract = (imax-imin)/(W_HEIGHT-1);
	re_cord = rmin + x*re_fract;
	im_cord = imax - y*im_fract;
	re_Z = re_C;
	im_Z = im_C;
	re2_Z = re_Z*re_Z;
	im2_Z = im_Z*im_Z;
	im_C = imax - y*im_fract;
	re_C = rmin + x*re_fract;
	n = 0;
	re_Z = 0;
	im_Z = 0;
	
	y = 0;
	while(y < W_HEIGHT)
	{
			x = 0;
			while(x < W_WIDTH)
			{
				im_C = imax - y*im_fract;
				re_C = rmin + x*re_fract;
				b_veric = TRUE;	
				n = 0;
				re_Z = 0;
				im_Z = 0;
				while(n < MAXCONT)
				{
					
					if(re_Z*re_Z + im_Z*im_Z > 4)
					{ 
						b_veric = FALSE;
						break;
					}
					tmp = 2*re_Z*im_Z + im_C;
					re_Z = re_Z*re_Z - im_Z*im_Z + re_C;
					im_Z = tmp;
					n++;
				}
				if(b_veric)
				{
					img_pix_put(img, x, y, color);
				}
				else
				{
					img_pix_put(img, x, y, 0x0*n);
				}
				x++;
			}
			y++;
			
	}
} */
