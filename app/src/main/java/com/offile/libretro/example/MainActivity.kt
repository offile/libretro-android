/**
 *     Copyright (C) 2021  offile
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

package com.offile.libretro.example

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.offile.libretro.Retro
import java.io.File

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val retro = Retro()
        retro.loadCore("core")
        retro.loadRom(initRom().absolutePath)
        retro.start()
    }

    private fun initRom(): File{
        val romName = "Adventure Island Classic (Europe).nes"
        val targetRom = filesDir.resolve(romName)
        if(!targetRom.exists()){
            val romData = assets.open(romName).readBytes()
            targetRom.writeBytes(romData)
        }
        return targetRom
    }
}
