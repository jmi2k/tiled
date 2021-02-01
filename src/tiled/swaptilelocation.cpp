/*
 * swaptilelocation.cpp
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

#include "swaptilelocation.h"

#include "tilesetdocument.h"

#include <QCoreApplication>

namespace Tiled {

SwapTileLocation::SwapTileLocation(TilesetDocument *tilesetDocument,
                     Tile *tile1,
                     Tile *tile2)
    : QUndoCommand(QCoreApplication::translate("Undo Commands",
                                               "Swap Tile Location"))
    , mTilesetDocument(tilesetDocument)
    , mTile1(tile1)
    , mTile2(tile2)
{}

void SwapTileLocation::swap()
{
    mTilesetDocument->swapTiles(mTile1, mTile2);
}

} // namespace Tiled
