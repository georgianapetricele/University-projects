import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { LoginPageComponent } from './pages/login-page/login-page.component';
import { HomePageComponent } from './pages/home-page/home-page.component';
import { AddPageComponent } from './pages/add-page/add-page.component';
import { RemovePageComponent } from './pages/remove-page/remove-page.component';
import { ShowPageComponent } from './pages/show-page/show-page.component';

const routes: Routes = [
  {path: '', component: LoginPageComponent},
  {path: 'homepage', component: HomePageComponent},
  {path: 'login', component: LoginPageComponent},
  {path: 'addPage', component: AddPageComponent},
  {path: 'deletePage', component: RemovePageComponent},
  {path: 'filterPage', component: ShowPageComponent}

];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
