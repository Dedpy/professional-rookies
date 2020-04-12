SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}
int CollisionParfaite(SDL_Surface* backgroundMask, SDL_Rect frame, SDL_Rect position)
{	
	SDL_Color couleur_obstacle={255,255,255};
	int i=0;
	int collision=0;
	SDL_Rect pos[8];

	pos[0].x=position.x;
	pos[0].y=position.y;
	pos[1].x=position.x+frame.w/2;
	pos[1].y=position.y;
	pos[2].x=position.x+frame.w;
	pos[2].y=position.y;

	pos[3].x=position.x;
	pos[3].y=position.y+frame.h/2;
	pos[4].x=position.x+frame.w;
	pos[4].y=position.y+frame.h/2;

	pos[5].x=position.x;
	pos[5].y=position.y+frame.h;
	pos[6].x=position.x+frame.w/2;
	pos[6].y=position.y+frame.h;
	pos[7].x=position.x+frame.w;
	pos[7].y=position.y+frame.h;

	while (i<8 && collision==0)
	{
		couleur_obstacle=GetPixel(backgroundMask,pos[i].x,pos[i].y);
		if (couleur_obstacle.r==0 && couleur_obstacle.g==0 && couleur_obstacle.b==0)
			collision=1;
		i++;
	}
	if (collision!=0)
	{
		if (i==0 || i==3 || i==5)
			collision=-1;
		else if (i==2 || i==4)
			collision=1;
		else if (i==1)
			collision=2;
		else
			collision=-2;
	}
	return collision;
}