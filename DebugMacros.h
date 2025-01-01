#pragma once

#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 24, FColor::Red, true);
#define DRAW_SPHERE_SingleFrame(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 24, FColor::Red, false,-1.f);

#define DRAW_LINE(Location,End) if(GetWorld()) DrawDebugLine(GetWorld(), Location, End, FColor::Red, true, -1.f, 0,1.f);
#define DRAW_LINE_SingleFrame(Location,End) if(GetWorld()) DrawDebugLine(GetWorld(), Location, End, FColor::Red, false, -1.f, 0,1.f);

#define DRAW_POINT(End) if(GetWorld()) DrawDebugPoint(GetWorld(), End, 15.f, FColor::Red, true);
#define DRAW_POINT_SingleFrame(End) if(GetWorld()) DrawDebugPoint(GetWorld(), End, 15.f, FColor::Red, false,-1.f);

#define DRAW_VECTOR(Location,End) if(GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), Location, End, FColor::Red, true, -1.f, 0,1.f); \
		DrawDebugPoint(GetWorld(), End, 15.f, FColor::Red, true); \
	}
#define DRAW_VECTOR_SingleFrame(Location,End) if(GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), Location, End, FColor::Red, false, -1.f, 0,1.f); \
		DrawDebugPoint(GetWorld(), End, 15.f, FColor::Red, false,-1.f); \
	}