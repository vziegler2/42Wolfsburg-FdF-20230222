/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dots2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:13:07 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/22 13:50:17 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

void	ft_dots2(t_fdf *data, int x, int y)
{
	double	xw;
	double	yw;

	data->zr = data->mtrx[data->dy][data->dx];
	data->zn = data->mtrx[y][x];
	data->xr = data->dx * data->zoom;
	data->xn = x * data->zoom;
	data->yr = data->dy * data->zoom;
	data->yn = y * data->zoom;
	data->xr += 1250;
	data->xn += 1250;
	data->yr -= 750;
	data->yn -= 750;
	data->xr = (data->xr - data->yr) * 0.5;
	data->yr = (data->xr + data->yr) * 0.5 - (data->zr * data->depth);
	data->xn = (data->xn - data->yn) * 0.5;
	data->yn = (data->xn + data->yn) * 0.5 - (data->zn * data->depth);
	xw = data->xn - data->xr;
	yw = data->yn - data->yr;
	xw /= fmax(fabs(data->xn - data->xr), fabs(data->yn - data->yr));
	yw /= fmax(fabs(data->xn - data->xr), fabs(data->yn - data->yr));
	ft_draw(data, xw, yw);
}

//Z. 21-22 -> zr = aktueller Matrixwert, zn = Matrixwert des nächsten Punktes
//Z. 23-26 -> shift bewirkt eine Verlängerung der Linien
//Z. 27-30 -> Erzeugt eine mittige Darstellung der Modelle
//         -> xr++ -> xr + 0,5; yr + 0,25 -> Flache Verschiebung rechts unten
//		   -> yr-- -> xr + 0,5; yr - 0,25 -> Flache Verschiebung rechts oben
//Z. 31-34 -> xr/yr ist der aktuelle Punkt, xn/yn ist der nächste Punkt
//		   -> Verzerrung des Modells durch einmal/zweimal * 0,5
//         -> Die rechte obere und linke untere Ecke werden nach außen,
//         -> die linke obere und rechte untere Ecke nach innen verzogen.
//Z. 31,33 -> Teil nach Minus verschiebt y gemäß dem Wert in der Matrix
//		   -> Minus, weil y nach unten im Bild wächst
//		   -> Delta xr wird einmal in Z. 31 halbiert,
//		   -> ein zweites Mal in yr -> Verzerrung 
//Z. 35-36 -> x- und y-Entfernung zwischen aktuellem und neuem Punkt
//Z. 37-38 -> Erzeugen die Steigung.
//         -> xw beschreibt die horizontale Verschiebung nach rechts,
//         -> yw die vertikale Verschiebung nach unten nach jedem Print.
//         -> fmax -> Eines von beiden ist 1, das andere zwischen 0 und 1.
//		   -> fabs, damit das Vorzeichen nicht mehr verändert wird.