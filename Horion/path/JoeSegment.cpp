#include "JoeSegment.h"

#include "../DrawUtils.h"

JoeSegment::JoeSegment(JoeSegmentType type, vec3_ti& start, vec3_ti& stop) : segmentType(type), start(start), end(stop) {
}
void JoeSegment::draw() {
	switch (segmentType) {
		case DROP: {
			auto dropPoint = start.toVec3t().add(0.5f, 0, 0.5f);
			dropPoint.x = end.x + 0.5f;
			dropPoint.z = end.z + 0.5f;
			DrawUtils::drawLine3d(start.toVec3t().add(0.5f, 0, 0.5f), dropPoint, 1);
			DrawUtils::drawLine3d(dropPoint, end.toVec3t().add(0.5f, 0, 0.5f), 1);
		} break;
		case JUMP:
			DrawUtils::drawLine3d(start.toVec3t().add(0.5f, 0, 0.5f), start.toVec3t().add(0.5f, 1, 0.5f), 1);
			DrawUtils::drawLine3d(start.toVec3t().add(0.5f, 1, 0.5f), end.toVec3t().add(0.5f, 0, 0.5f), 1);
			break;
		case WALK:
		default:
			DrawUtils::drawLine3d(start.toVec3t().add(0.5f, 0, 0.5f), end.toVec3t().add(0.5f, 0, 0.5f), 1);
			break;
	}
}
