#include <stdio.h>

#include <vips/vips.h>

int
main (int argc, char **argv)
{
  VipsImage *im;
  VipsImage *out;
  
  

  if (VIPS_INIT (argv[0]))
    vips_error_exit ("unable to start VIPS");

  
//code for image1.jpg
  if (!(im = vips_image_new_from_file (argv[1], NULL)))
    vips_error_exit ("unable to open");
  
    
  if (vips_resize (im, &out, 0.1171875,"vscale",0.208333333 ,NULL))
   vips_error_exit ("not able to scale");
   
  if (vips_image_write_to_file (out, "image1_naive.jpg", NULL))
       vips_error_exit ("write error");

   if (vips_thumbnail_image (im, &out,150,"size",VIPS_SIZE_BOTH,"crop",VIPS_INTERESTING_ENTROPY,NULL))
    vips_error_exit ("not able to scale");

  if (vips_image_write_to_file (out, "image1_decent.jpg", NULL))
       vips_error_exit ("write error");


  
  g_object_unref (im);
  g_object_unref (out);

//end of code for image1.jpg


//code for image4.png 

  VipsImage *im4;
  VipsImage *out4;
 

   if (!(im4 = vips_image_new_from_file (argv[2], NULL)))
    vips_error_exit ("unable to open");

   if (vips_resize (im4, &out4, 0.06,"vscale",0.06 ,NULL))
   vips_error_exit ("not able to scale"); //its a square so resize its enough
   
 

  if (vips_image_write_to_file (out4, "image4_modified.png", NULL))
       vips_error_exit ("write error");

  g_object_unref (im4);
  g_object_unref (out4);

//end of code for image4.png


//code for image5.png 

    VipsImage *im5;
    VipsImage *out5;
 

   if (!(im5 = vips_image_new_from_file (argv[3], NULL)))
    vips_error_exit ("unable to open");

  if (vips_resize (im5, &out5, 0.078125,"vscale",0.1175548 ,NULL))
   vips_error_exit ("not able to scale"); 
   
   
 

  if (vips_image_write_to_file (out5, "image5_modified.png", NULL))
       vips_error_exit ("write error");

  g_object_unref (im5);
  g_object_unref (out5);

//end of code for image 5
   
   
  
//code for image2.svg
  
   VipsImage *im2;
    VipsImage *out2;
   
  if (!(im2 = vips_image_new_from_file (argv[4], NULL)))
    vips_error_exit ("unable to open");
  
    

   
  

   if (vips_thumbnail_image (im2, &out2,150,"size",VIPS_SIZE_BOTH,"crop",VIPS_INTERESTING_ENTROPY,NULL))
    vips_error_exit ("not able to scale");

  if (vips_image_write_to_file (out2, "image2_modified.png", NULL))
       vips_error_exit ("write error");


  
  g_object_unref (im2);
  g_object_unref (out2);

//end of code for image2.svg















  return (0);
}
