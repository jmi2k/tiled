/*
 * relocatetile.h
 * Copyright 2015, Alexander "theHacker" Münch <git@thehacker.biz>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "undocommands.h"

#include <QUndoCommand>

namespace Tiled {

class Tile;

class TilesetDocument;

/**
 * A command that changes the location of a tile on the tileset.
 */
class RelocateTile : public QUndoCommand
{
public:
    /**
     * Constructor.
     *
     * @param tilesetDocument the tileset document that's being edited
     * @param tile            the source tile
     * @param location        the target location
     */
    RelocateTile(TilesetDocument *tilesetDocument,
              Tile *tile,
              int location);

    void undo() { relocate(mTile, mLocation); }
    void redo() { relocate(mTile, mPrevLocation); }

private:
    void relocate(const Tile *tile, int location);

    TilesetDocument *mTilesetDocument;
    Tile *mTile;
    int mLocation;
    int mPrevLocation;
};

} // namespace Tiled
